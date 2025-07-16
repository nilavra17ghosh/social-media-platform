#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "reply.h"
#include "post.h"
#include "platform.h"
Comment* createComment(char* username, char* content)
{
    if (username == NULL || content == NULL) {
        return NULL;
    }
    
    Comment* comment = (Comment*)malloc(sizeof(Comment));
    if (comment == NULL) {
        return NULL;
    }
    
    comment->username = (char*)malloc(strlen(username) + 1);
    comment->content = (char*)malloc(strlen(content) + 1);
    if (comment->username == NULL || comment->content == NULL) {
        free(comment->username);
        free(comment->content);
        free(comment);
        return NULL;
    }
    
    strcpy(comment->username, username);
    strcpy(comment->content, content);
    
    comment->replies = NULL;
    comment->next = NULL;
    return comment;
}

void print_comment(Comment* comment)
{
    if (comment == NULL) {
        return;
    }
    
    printf("**************\n");
    printf("%s\n", comment->username);
    printf("%s\n", comment->content);
    return;
}
void print_comment_linked (Comment* comment)
{
    Comment* temp = comment;
    if (temp == NULL)
    {
        printf("No comments to print\n");
        return;
    }
    else
    {
        while(temp != NULL)
        {
            print_comment(temp);
            temp = temp->next;
        }
    }
}

void freeComment(Comment* comment)
{
    if (comment == NULL) {
        return;
    }
    
    free(comment->username);
    free(comment->content);
    freeReplyList(comment->replies);
    free(comment);
}

void freeCommentList(Comment* head)
{
    while (head != NULL) {
        Comment* temp = head;
        head = head->next;
        freeComment(temp);
    }
}