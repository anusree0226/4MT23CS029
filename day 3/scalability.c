#include <stdio.h>
#include <stdlib.h>
#define MAX_USERS 500000
int main() {
    unsigned int current_users = 0;
    unsigned int new_users;
      printf("Enter the number of users trying to access the platform: ");
    scanf("%u", &new_users);
      current_users += new_users;
    if (current_users > MAX_USERS) {
        printf("Platform Crash! Maximum capacity exceeded.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Platform running smoothly with %u users.\n", current_users);
    }
       return 0;
}
