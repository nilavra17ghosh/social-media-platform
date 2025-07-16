#ifndef COMMENT_H
#define COMMENT_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "reply.h"

typedef struct Comment {
    char* username;
    char* content;
    Reply* replies;
    struct Comment* next;
} Comment;

Comment* createComment(char* username, char* content);
void print_comment_linked (Comment* comment);
void freeComment(Comment* comment);
void freeCommentList(Comment* head);

#endif