#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "comment.h"
#include "reply.h"
#include "post.h"
#include "platform.h"
Platform *createPlatform()
{
    Platform *platform = (Platform *)malloc(sizeof(Platform));
    if (platform == NULL) {
        return NULL;
    }
    
    platform->posts = NULL;
    platform->lastViewedPost = NULL;
    platform->next = NULL;
    return platform;
}

bool addPost(Platform *platform, char *username, char *caption)
{
    if (platform == NULL || username == NULL || caption == NULL) {
        return false;
    }
    
    Post *new = createPost(username, caption);
    if (new == NULL)
    {
        return false;
    }
    new->next = platform->posts;
    platform->posts = new;
    platform->lastViewedPost = new;
    return true;
}
bool deletePost(Platform *platform, int n)
{
    if (platform == NULL || n < 1 || platform->posts == NULL) {
        return false;
    }
    
    Post *curr = platform->posts;
    Post *prev = NULL;
    
    // Navigate to the nth post (1-based indexing)
    for (int i = 1; i < n && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        return false; // Post doesn't exist
    }
    
    // Update lastViewedPost if we're deleting it
    if (platform->lastViewedPost == curr) {
        platform->lastViewedPost = curr->next ? curr->next : prev;
    }
    
    // Remove the post from the list
    if (prev == NULL) {
        platform->posts = curr->next;
    } else {
        prev->next = curr->next;
    }
    
    // Free memory
    free(curr->username);
    free(curr->caption);
    // TODO: Free all comments and replies recursively
    free(curr);
    
    return true;
}
Post *viewPost(Platform *platform, int n)
{
    if (n < 1 || platform == NULL || platform->posts == NULL)
    {
        return NULL;
    }
    Post *curr = platform->posts;
    for (int i = 0; i < n - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    platform->lastViewedPost = curr;
    return curr;
}

Post *currPost(Platform *platform)
{
    if (platform == NULL)
    {
        return NULL;
    }
    Post *lastViewedPost = platform->lastViewedPost;
    return lastViewedPost;
}
Post *nextPost(Platform *platform)
{
    if (platform == NULL || platform->lastViewedPost == NULL)
    {
        return NULL;
    }
    Post *nextPost = platform->lastViewedPost->next;
    if (nextPost == NULL)
    {
        return NULL;
    }
    platform->lastViewedPost = nextPost;
    return platform->lastViewedPost;
}

Post *previousPost(Platform *platform)
{
    if (platform == NULL || platform->posts == NULL || platform->lastViewedPost == NULL) {
        return NULL;
    }
    
    Post *curr = platform->posts;
    Post *prev = NULL;
    while (curr != NULL && curr != platform->lastViewedPost)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL)
    {
        platform->lastViewedPost = prev;
        return prev;
    }
    else
    {
        return NULL;
    }
}
bool addComment(Platform *platform, char *username, char *content)
{
    if (platform == NULL)
    {
        return false;
    }
    if (platform->lastViewedPost == NULL)
    {
        return false;
    }
    Comment *newComment = createComment(username, content);
    if (newComment == NULL)
    {
        return false;
    }
    newComment->next = platform->lastViewedPost->comments;
    platform->lastViewedPost->comments = newComment;
    return true;
}
bool deleteComment(Platform *platform, int n)
{
    if (platform == NULL || platform->lastViewedPost == NULL || 
        platform->lastViewedPost->comments == NULL || n < 1) {
        return false;
    }
    
    Comment *curr = platform->lastViewedPost->comments;
    Comment *prev = NULL;
    
    // Navigate to the nth comment (1-based indexing)
    for (int i = 1; i < n && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        return false; // Comment doesn't exist
    }
    
    // Remove the comment from the list
    if (prev == NULL) {
        platform->lastViewedPost->comments = curr->next;
    } else {
        prev->next = curr->next;
    }
    
    // Free memory
    free(curr->username);
    free(curr->content);
    // TODO: Free all replies recursively
    free(curr);
    
    return true;
}
Comment *viewComments(Platform *platform)
{
    if (platform == NULL)
    {
        return NULL;
    }
    Post *lastViewedPost = platform->lastViewedPost;
    if (lastViewedPost != NULL && lastViewedPost->comments != NULL)
    {
        return lastViewedPost->comments;
    }
    else
    {
        return NULL;
    }
}
bool addReply(Platform *platform, char *username, char *content, int n)
{
    if (platform == NULL || username == NULL || content == NULL || n < 1 ||
        platform->lastViewedPost == NULL || platform->lastViewedPost->comments == NULL) {
        return false;
    }
    
    Comment *currentComment = platform->lastViewedPost->comments;
    
    // Navigate to the nth comment (1-based indexing)
    for (int i = 1; i < n && currentComment != NULL; i++) {
        currentComment = currentComment->next;
    }
    
    if (currentComment == NULL) {
        return false;
    }
    
    Reply *newReply = createReply(username, content);
    if (newReply == NULL) {
        return false;
    }
    
    // Add reply to the end of the reply list
    if (currentComment->replies == NULL) {
        currentComment->replies = newReply;
    } else {
        Reply *lastReply = currentComment->replies;
        while (lastReply->next != NULL) {
            lastReply = lastReply->next;
        }
        lastReply->next = newReply;
    }
    
    return true;
}
bool deleteReply(Platform *platform, int n, int m)
{
    if (platform == NULL || platform->lastViewedPost == NULL || 
        platform->lastViewedPost->comments == NULL || n < 1 || m < 1) {
        return false;
    }
    
    Comment *currentComment = platform->lastViewedPost->comments;
    
    // Navigate to the nth comment (1-based indexing)
    for (int i = 1; i < n && currentComment != NULL; i++) {
        currentComment = currentComment->next;
    }
    
    if (currentComment == NULL || currentComment->replies == NULL) {
        return false;
    }
    
    Reply *curr = currentComment->replies;
    Reply *prev = NULL;
    
    // Navigate to the mth reply (1-based indexing)
    for (int i = 1; i < m && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        return false; // Reply doesn't exist
    }
    
    // Remove the reply from the list
    if (prev == NULL) {
        currentComment->replies = curr->next;
    } else {
        prev->next = curr->next;
    }
    
    // Free memory
    free(curr->username);
    free(curr->content);
    free(curr);
    
    return true;
}