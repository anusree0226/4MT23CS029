#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int isRegistered;
} User;

User  users[MAX_USERS];
int userCount = 0;

void registerUser ();
void makePayment();
void viewUsers();
void adminInterface();

int main() {
    int choice;

    while (1) {
        printf("\n--- Payment Portal ---\n");
        printf("1. Register User\n");
        printf("2. Make Payment\n");
        printf("3. Admin Interface\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser ();
                break;
            case 2:
                makePayment();
                break;
            case 3:
                adminInterface();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void registerUser () {
    if (userCount >= MAX_USERS) {
        printf("User  limit reached. Cannot register more users.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("User  already registered.\n");
            return;
        }
    }

    strcpy(users[userCount].name, name);
    users[userCount].isRegistered = 1;
    userCount++;
    printf("User  registered successfully!\n");
}

void makePayment() {
    char name[MAX_NAME_LENGTH];
    int amount;

    printf("Enter your name: ");
    scanf("%s", name);

    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User  not registered. Please register first.\n");
        return;
    }

    printf("Enter payment amount (INR): ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    float commission = amount * 0.02;
    float totalAmount = amount + commission;

    printf("Processing payment...\n");
    printf("Amount: INR %d\n", amount);
    printf("Commission (2%%): INR %.2f\n", commission);
    printf("Total Amount to be paid: INR %.2f\n", totalAmount);
    printf("Payment successful! Thank you for your transaction.\n");
}

void viewUsers() {
    if (userCount == 0) {
        printf("No registered users.\n");
        return;
    }

    printf("\n--- Registered Users ---\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d. %s\n", i + 1, users[i].name);
    }
}

void adminInterface() {
    int adminChoice;

    while (1) {
        printf("\n--- Admin Interface ---\n");
        printf("1. View Registered Users\n");
        printf("2. Exit Admin Interface\n");
        printf("Select an option: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                viewUsers();
                break;
            case 2:
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
