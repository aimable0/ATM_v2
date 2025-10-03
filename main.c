#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TOT_USERS 4

#define MAX_TRANSACTIONS 5


//Function Prototypes
void atm();
void atmMenu();
void checkBalance();
void deposit();
void withdraw();
void viewTransactions();
void logTransaction(const char *action);

float balance = 0;
char transactions[MAX_TRANSACTIONS][50];
int transaction_count = 0;

typedef struct
{
    char username[15];
    char pincode[5];
} User;

int main(void)
{
    User users[TOT_USERS];

    // user 1
    strcpy(users[0].username, "karake");
    strcpy(users[0].pincode, "0001");

    // user 2
    strcpy(users[1].username, "simeon");
    strcpy(users[1].pincode, "0002");

    // user 3
    strcpy(users[2].username, "manzi");
    strcpy(users[2].pincode, "0003");

    // user 4
    strcpy(users[3].username, "levis");
    strcpy(users[3].pincode, "0004");

    // get user's credentials
    char u_username[15];
    char u_pincode[5];

    start:;
    printf("-------- LOG IN ---------\n");
    printf("Enter username (q to quit): ");
    scanf("%s", u_username);

    // see if the user want to quit
    if (u_username[0] == 'q' && u_username[1] == '\0') {
        printf("Thank you for using our service!\n");
        return 0;
    }

    bool user = false;
    for (int i = 0; i < TOT_USERS; i++)
    {
        if (strcmp(users[i].username, u_username) == 0) {
            user = true;
            break;
        }

    }
    if (!user) {
        printf("Invalid username !\n");
        goto start;
    }

    printf("Enter pincode: ");
    scanf("%s", u_pincode);

    bool valid_user = false;
    int i = 0;
    for (i = 0; i < TOT_USERS; i++) {
        if (strcmp(users[i].username, u_username) == 0 && strcmp(users[i].pincode, u_pincode) == 0) {
            valid_user = true;
            break;
        }
    }

    if (valid_user == true) {
        printf("\nHello, %s!\n\n", users[i].username);
        // place ATM HERE
        atm();
        goto start;

    } else {
        printf("Oops, not found in our database! try a different username or pincode.\n");
    }

	    return 0;
}

// ATM Function Definitions
void atm() {
    printf("------------------ ATM Menu---------------\n");
    atmMenu();
    printf("\nThank you for using ATM. Goodbye!\n");
}

void atmMenu() {
    int choice;
    do {
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Transactions\n");
        printf("5. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkBalance(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: viewTransactions(); break;
            case 5: printf("Exiting ATM...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

void checkBalance() {
    printf("Your current balance is: $%.2f\n", balance);
    logTransaction("Checked balance");
}


void deposit() {
    float amount;
    printf("Enter deposit amount: $");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Successfully deposited $%.2f\n", amount);

        char log[50];
        sprintf(log, "Deposited $%.2f", amount);
        logTransaction(log);
    } else {
        printf("Invalid deposit amount.\n");
    }
}


void withdraw() {
    float amount;
    printf("Enter withdrawal amount: $");
    scanf("%f", &amount);

    if (amount > 0 && balance >= amount) {
        balance -= amount;
        printf("Successfully withdrew $%.2f\n", amount);

        char log[50];
        sprintf(log, "Withdrew $%.2f", amount);
        logTransaction(log);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}


void viewTransactions() {
    printf("\n------------------ Transaction History ------------------\n");
    if (transaction_count == 0) {
        printf("No transactions yet.\n");
    } else {
        for (int i = 0; i < transaction_count; i++) {
            printf("%d. %s\n", i + 1, transactions[i]);
        }
    }
}


void logTransaction(const char *action) {
    if (transaction_count < MAX_TRANSACTIONS) {
        strcpy(transactions[transaction_count], action);
        transaction_count++;
    } else {
        // Shift old transactions up to make space
        for (int i = 1; i < MAX_TRANSACTIONS; i++) {
            strcpy(transactions[i - 1], transactions[i]);
        }
        strcpy(transactions[MAX_TRANSACTIONS - 1], action);
    }
}

