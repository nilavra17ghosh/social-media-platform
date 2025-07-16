#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "comment.h"
#include "reply.h"
#include "post.h"
#include "platform.h"
Reply* createReply(char* username, char* content)
{
    if (username == NULL || content == NULL) {
        return NULL;
    }
    
    Reply *reply = (Reply*)malloc(sizeof(Reply));
    if (reply == NULL) {
        return NULL;
    }
    
    reply->username = (char*)malloc(strlen(username) + 1);
    reply->content = (char*)malloc(strlen(content) + 1);
    if (reply->username == NULL || reply->content == NULL) {
        free(reply->username);
        free(reply->content);
        free(reply);
        return NULL;
    }
    
    strcpy(reply->username, username);
    strcpy(reply->content, content);
    
    reply->next = NULL;
    return reply;
}

void freeReply(Reply* reply)
{
    if (reply == NULL) {
        return;
    }
    
    free(reply->username);
    free(reply->content);
    free(reply);
}

void freeReplyList(Reply* head)
{
    while (head != NULL) {
        Reply* temp = head;
        head = head->next;
        freeReply(temp);
    }
}