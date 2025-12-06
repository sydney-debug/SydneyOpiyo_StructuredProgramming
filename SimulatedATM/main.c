#include <stdio.h>
#include <stdlib.h>

int login();
void showMenu();
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);

int main() {
    float balance = 1000.00;

    if (!login()) {
        printf("Too many failed attempts. Exiting...\n");
        system("pause");
        return 0;
    }

    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdraw(balance);
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}


int login() {
    int correctPIN = 2024;
    int userPIN;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &userPIN);

        if (userPIN == correctPIN) {
            printf("Access Granted.\n\n");
            return 1;
        } else {
            printf("Incorrect PIN. Try again.\n");
            attempts++;
        }
    }

    return 0;
}


void showMenu() {
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}


void checkBalance(float balance) {
    printf("Your current balance is: KES %.2f\n", balance);
}

float deposit(float balance) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Deposit must be positive.\n");
    } else {
        balance += amount;
        printf("Deposit successful! New balance: KES %.2f\n", balance);
    }

    return balance;
}

float withdraw(float balance) {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Withdrawal must be positive.\n");
    }
    else if (amount > balance) {
        printf("Insufficient balance! You only have KES %.2f\n", balance);
    }
    else {
        balance -= amount;
        printf("Withdrawal successful! New balance: KES %.2f\n", balance);
    }
         system("pause");

    return balance;
}

