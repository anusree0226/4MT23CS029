#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[50];
    int age;
    char contact[15];
    char travelDate[20];
    char busType[20];
    int ticketPrice;
    char paymentMethod[20];
    int paymentAmount;
    char transactionID[20];
} Ticket;

Ticket tickets[MAX];
int ticketCount = 0;

int calculatePrice(char *busType, char *travelDate) {
    if (strcmp(busType, "AC") == 0) return 1000;
    if (strcmp(busType, "Non-AC") == 0) return 700;
    return 500;
}

void bookTicket() {
    Ticket t;
    printf("Enter passenger name: ");
    scanf("%s", t.name);
    printf("Enter age: ");
    scanf("%d", &t.age);
    printf("Enter contact number: ");
    scanf("%s", t.contact);
    printf("Enter travel date (DD/MM/YYYY): ");
    scanf("%s", t.travelDate);
    printf("Enter bus type (AC/Non-AC/General): ");
    scanf("%s", t.busType);
    
    t.ticketPrice = calculatePrice(t.busType, t.travelDate);
    printf("Ticket price: %d\n", t.ticketPrice);
    
    printf("Enter payment method (Card/Cash): ");
    scanf("%s", t.paymentMethod);
    printf("Enter payment amount: ");
    scanf("%d", &t.paymentAmount);
    printf("Enter transaction ID: ");
    scanf("%s", t.transactionID);
    
    tickets[ticketCount++] = t;
    printf("Ticket booked successfully!\n");
}

void displayTickets() {
    printf("\nBooked Tickets:\n");
    for (int i = 0; i < ticketCount; i++) {
        printf("Passenger: %s, Age: %d, Contact: %s, Travel Date: %s, Bus Type: %s, Price: %d, Payment: %s, Transaction ID: %s\n", 
               tickets[i].name, tickets[i].age, tickets[i].contact, tickets[i].travelDate, tickets[i].busType, tickets[i].ticketPrice, tickets[i].paymentMethod, tickets[i].transactionID);
    }
}

void cancelTicket() {
    char transactionID[20];
    printf("Enter transaction ID for cancellation: ");
    scanf("%s", transactionID);
    
    for (int i = 0; i < ticketCount; i++) {
        if (strcmp(tickets[i].transactionID, transactionID) == 0) {
            printf("Ticket for %s canceled. Refund of %d initiated.\n", tickets[i].name, tickets[i].ticketPrice);
            for (int j = i; j < ticketCount - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            ticketCount--;
            return;
        }
    }
    printf("Transaction ID not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Book Ticket\n2. Display Tickets\n3. Cancel Ticket\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: bookTicket(); break;
            case 2: displayTickets(); break;
            case 3: cancelTicket(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}
