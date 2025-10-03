#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TOT_USERS 4
#define INITIAL_BALANCE 0.00
#define MAX_TRANSACTIONS 5

// Function declarations
void viewTransactions();
void logTransaction(const char *action);
void check_balance(double balance);
double deposit(double current_balance, double amount);
double withdraw(double current_balance, double amount);
void atm(void);
void clearTransactions(char transactions[], int transaction_count);

// Global variables
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

    // user provided credentials
    char u_username[15];
    char u_pincode[5];

    login_again:
    printf("-------- LOG IN ---------\n");

    login:
    printf("Enter username (q to quit): ");
    scanf("%s", u_username);

    // quit
    if (u_username[0] == 'q' && u_username[1] == '\0') {
        printf("Good bye! ...\n");
        return 0;
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
        atm();
        goto login_again;
    } else {
        printf("Oops, login failed! try a different username or pincode.\n");
        goto login;
    }

    return 0;
}



// Function implementations
void check_balance(double balance) {
    printf("\n$$ Current Balance: $%.2f\n\n", balance);
}

double deposit(double current_balance, double amount) {
    return current_balance + amount;
}

double withdraw(double current_balance, double amount) {
    return current_balance - amount;
}

void atm(void) {
    int usr_choice = 0;
    double balance = INITIAL_BALANCE;
    double amount = 0.00;
    char log[50]; // to store transaction details

    printf("============ ATM (SIMULATOR) ===========\n\n");

    while (1) {
        // Display menu
        printf("Choose:\n");
        printf("  (1) Deposit Money\n");
        printf("  (2) Check Account Balance\n");
        printf("  (3) Withdraw Money\n");
        printf("  (4) Transaction history\n");
        printf("  (5) Logout\n\n");

        // Get user choice
        printf("(prompt) Choose action [1-4]: ");
        if (scanf("%d", &usr_choice) != 1) {
            printf("Invalid input. Please enter a number!\n\n");
            // clear invalid buffer
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n'); // clear any leftover input

        // Handle user choice
        switch (usr_choice) {
            case 1: // Deposit
                printf("\n$$ Enter amount to deposit: ");
                scanf("%lf", &amount);

                // clear any leftover input
                while(getchar() != '\n');

                if (amount <= 0) {
                    printf("Invalid amount! Must be greater than 0.\n\n");
                } else {
                    balance = deposit(balance, amount);
                    printf("++ $%.2f deposited successfully!\n\n", amount);
                }
                // saving transaction
                sprintf(log, "Deposited $%.2f", amount);
                logTransaction(log);
                break;

            case 2: // Check balance
                check_balance(balance);

                // saving transaction
                sprintf(log, "Checked balance $%.2f", amount);
                logTransaction(log);
                break;

            case 3: // Withdraw
                printf("\n$$ Enter amount to withdraw: ");
                scanf("%lf", &amount);

                // clear any leftover input
                while(getchar() != '\n');

                if (amount <= 0) {
                    printf("Invalid amount! Must be greater than 0.\n\n");
                } else if (amount > balance) {
                    printf("Not enough funds! Current balance: $%.2f\n\n", balance);
                } else {
                    balance = withdraw(balance, amount);
                    printf("-- Withdrawal of $%.2f successful.\n\n", amount);
                    check_balance(balance);
                }

                // saving transaction
                sprintf(log, "Withdrew $%.2f", amount);
                logTransaction(log);
                break;

            case 4:
                viewTransactions();
                printf("\n");
                break;
            case 5: // Exit
                // clearTransactions(transactions, transaction_count);
                transaction_count = 0; // reset transaction count.
                printf("\n... Goodbye! Thanks for using ATM Simulator ...\n\n");
                return;

            default:
                printf("Oops! Invalid option. Please choose between 1-4.\n\n");
                break;
        }
    }

}

// loggin transaction functions
void viewTransactions() {
    printf("\n------- Transaction History ---------\n");
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

// void clearTransactions(char transactions[], int transaction_count)
// {
//     char log[50]; // to store transaction details
//     int amt = 0;
//     for (int i = 0; i < transaction_count; i++) {
//         sprintf(log, "Empty transaction", amt);
//         logTransaction(log);
//     }
// }