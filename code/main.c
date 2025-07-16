#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "comment.h"
#include "reply.h"
#include "post.h"
#include "platform.h"
int main()
{ 
    Platform *platform = createPlatform();
    if (platform == NULL) {
        printf("Failed to create platform\n");
        return 1;
    }
    
    bool x = true;
    while (x)
    {  
        char task[50];
        if (scanf("%49s", task) != 1) {
            break;
        }
        
        if (strcmp(task, "add_post") == 0)
        {
            char username[100], caption[100];
            if (scanf("%99s %99s", username, caption) == 2) {
                bool abc = addPost(platform, username, caption);
                if (!abc) {
                    printf("Failed to add post\n");
                }
            }
        }
        else if (strcmp(task, "add_comment") == 0)
        {
            char username[100], content[100];
            if (scanf("%99s %99s", username, content) == 2) {
                bool abc = addComment(platform, username, content);
                if (!abc) {
                    printf("Failed to add comment\n");
                }
            }
        }
        else if (strcmp(task, "add_reply") == 0)
        {
            char username[100], content[100];
            int n;
            if (scanf("%99s %99s %d", username, content, &n) == 3) {
                bool abc = addReply(platform, username, content, n);
                if (!abc) {
                    printf("Failed to add reply\n");
                }
            }
        }
        else if (strcmp(task, "delete_post") == 0)
        {
            int n;
            if (scanf("%d", &n) == 1) {
                bool abc = deletePost(platform, n);
                if (!abc) {
                    printf("Failed to delete post\n");
                }
            }
        }
        else if (strcmp(task, "delete_comment") == 0)
        {
            int n;
            if (scanf("%d", &n) == 1) {
                bool abc = deleteComment(platform, n);
                if (!abc) {
                    printf("Failed to delete comment\n");
                }
            }
        }
        else if (strcmp(task, "delete_reply") == 0)
        {   
            int m, n;
            if (scanf("%d %d", &n, &m) == 2) {
                bool abc = deleteReply(platform, n, m);
                if (!abc) {
                    printf("Failed to delete reply\n");
                }
            }
        }
        else if(strcmp(task, "view_post") == 0)
        {
            int n;
            if (scanf("%d", &n) == 1) {
                Post* d = viewPost(platform, n);
                if (d != NULL) {
                    print_post(d);
                } else {
                    printf("Post not found\n");
                }
            }
        }
        else if(strcmp(task, "view_comments") == 0)
        {
            Comment *d = viewComments(platform);
            print_comment_linked(d);
        }
        else if(strcmp(task, "previous_post") == 0)
        {
            Post *d = previousPost(platform);
            if (d != NULL) {
                print_post(d);
            } else {
                printf("No previous post\n");
            }
        }
        else if(strcmp(task, "current_post") == 0)
        {
            Post *d = currPost(platform);
            if (d != NULL) {
                print_post(d);
            } else {
                printf("No current post\n");
            }
        }
        else if(strcmp(task, "next_post") == 0)
        {
            Post *d = nextPost(platform);
            if (d != NULL) {
                print_post(d);
            } else {
                printf("No next post\n");
            }
        }
        else if(strcmp(task, "exit") == 0)
        {
            x = false;
        }
        else {
            printf("Unknown command: %s\n", task);
        }
    }
    
    // TODO: Free all memory before exit
    return 0;
}
