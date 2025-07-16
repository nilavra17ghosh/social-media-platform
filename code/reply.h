#ifndef REPLY_H
#define REPLY_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Reply {
    char* username;
    char* content;
    struct Reply* next;
} Reply;

Reply* createReply(char* username, char* content);
void freeReply(Reply* reply);
void freeReplyList(Reply* head);

#endif