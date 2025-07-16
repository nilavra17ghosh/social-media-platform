#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
 #include "comment.h"
 #include "reply.h"
 #include "post.h"

typedef struct Platform {
    Post* posts;
    Post* lastViewedPost;
    struct Platform* next;
} Platform;

Platform* createPlatform();

bool addPost(Platform* platform, char* username, char* caption);

bool addComment(Platform* platform, char* username, char* content);

bool addReply(Platform* platform, char* username, char* content, int n);

bool deletePost(Platform* platform, int n);

bool deleteComment(Platform* platform, int n);

bool deleteReply(Platform* platform, int n, int m);

Post* viewPost(Platform* platform, int n);

Comment* viewComments(Platform* platform);

Post* previousPost(Platform* platform);

Post* currPost(Platform* platform);

Post* nextPost(Platform* platform);

#endif
