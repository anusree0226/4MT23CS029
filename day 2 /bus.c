#include <stdio.h>
#include <string.h>

#define MAX_SEATS 10

typedef struct {
    char name[50];
    int age;
    char contact[15];
    int seatNumber;
} Passenger;

typedef struct {
    int busNumber;
    char route[100];
    char departureTime[10];
    int totalSeats;
    Passenger seats[MAX_SEATS];
    int availableSeats;
} Bus;

void initializeBus(Bus *bus) {
    bus->busNumber = 101;
    strcpy(bus->route, "City A to City B");
    strcpy(bus->departureTime, "10:00 AM");
    bus->totalSeats = MAX_SEATS;
    bus->availableSeats = MAX_SEATS;
    for (int i = 0; i < MAX_SEATS; i++) {
        bus->seats[i].seatNumber = 0;  // Indicating empty seat
    }
}

void allocateSeat(Bus *bus) {
    if (bus->availableSeats == 0) {
        printf("No seats available!\n");
        return;
    }
    Passenger p;
    printf("Enter passenger name: ");
    scanf("%s", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter contact number: ");
    scanf("%s", p.contact);
    
    for (int i = 0; i < MAX_SEATS; i++) {
        if (bus->seats[i].seatNumber == 0) { // Find first available seat
            p.seatNumber = i + 1;
            bus->seats[i] = p;
            bus->availableSeats--;
            printf("Seat allocated: %d\n", p.seatNumber);
            return;
        }
    }
}

void cancelSeat(Bus *bus, int seatNumber) {
    if (seatNumber < 1 || seatNumber > MAX_SEATS || bus->seats[seatNumber - 1].seatNumber == 0) {
        printf("Invalid or unallocated seat number!\n");
        return;
    }
    printf("Seat %d cancelled for %s\n", seatNumber, bus->seats[seatNumber - 1].name);
    bus->seats[seatNumber - 1].seatNumber = 0;
    bus->availableSeats++;
}

void displaySeats(Bus *bus) {
    printf("\nAllocated Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (bus->seats[i].seatNumber != 0) {
            printf("Seat %d - %s, Age: %d, Contact: %s\n", bus->seats[i].seatNumber, bus->seats[i].name, bus->seats[i].age, bus->seats[i].contact);
        }
    }
    printf("Available Seats: %d\n", bus->availableSeats);
}

int main() {
    Bus bus;
    initializeBus(&bus);
    int choice, seatNumber;
    
    while (1) {
        printf("\n1. Allocate Seat\n2. Cancel Seat\n3. Display Allocations\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                allocateSeat(&bus);
                break;
            case 2:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seatNumber);
                cancelSeat(&bus, seatNumber);
                break;
            case 3:
                displaySeats(&bus);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
