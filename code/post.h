#ifndef POST_H
#define POST_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "comment.h"

typedef struct Post {
    char* username;
    char* caption;
    Comment* comments;
    struct Post* next;
} Post;

Post* createPost(char* username, char* caption);
void print_post(Post* post);

#endif