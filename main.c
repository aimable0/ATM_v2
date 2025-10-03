#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TOT_USERS 4


typedef struct
{
    char username[15];
    char pincode[5];
} person;

int main(void)
{
    person users[TOT_USERS];

    // user 1
    strcpy(users[0].username, "karake");
    strcpy(users[0].pincode, "0001");

    // user 2
    strcpy(users[0].username, "simeon");
    strcpy(users[0].pincode, "0002");

    // user 3
    strcpy(users[0].username, "manzi");
    strcpy(users[0].pincode, "0003");

    // user 4
    strcpy(users[0].username, "levis");
    strcpy(users[0].pincode, "0004");

    // get user's credentials
    char u_username[15];
    char u_pincode[5];

    printf("Enter username: ");
    scanf("%s", u_username);

    printf("Enter pincode: ");
    scanf("%s", u_pincode);

    bool valid_user = false;
    for (int i = 0; i < TOT_USERS; i++) {
        if (strcmp(users[i].username, u_username) == 0 && strcmp(users[i].pincode, u_pincode) == 0)
            valid_user = true;
    }

    // ATM SYSTEM.
}
