#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "comment.h"
#include "reply.h"
#include "post.h"
#include "platform.h"
Post* createPost(char* username, char* caption)
{
    if (username == NULL || caption == NULL) {
        return NULL;
    }
    
    Post* post = (Post*)malloc(sizeof(Post));
    if (post == NULL) {
        return NULL;
    }
    
    post->username = (char*)malloc(strlen(username) + 1);
    post->caption = (char*)malloc(strlen(caption) + 1);
    if (post->username == NULL || post->caption == NULL) {
        free(post->username);
        free(post->caption);
        free(post);
        return NULL;
    }
    
    strcpy(post->username, username);
    strcpy(post->caption, caption);
    
    post->comments = NULL;
    post->next = NULL;
    return post;
}

void print_post(Post* post)
{
    if (post == NULL) {
        printf("No post to display\n");
        return;
    }
    
    printf("------------\n");
    printf("%s\n", post->username);
    printf("%s\n", post->caption);
    return;
}