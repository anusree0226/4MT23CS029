#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUSES 100

typedef struct {
    char busID[10];
    float latitude;
    float longitude;
    char timestamp[20];
    char route[50];
} BusLocation;

BusLocation buses[MAX_BUSES];
int busCount = 0;

void updateBusLocation() {
    BusLocation b;
    printf("Enter Bus ID: ");
    scanf("%s", b.busID);
    printf("Enter Latitude: ");
    scanf("%f", &b.latitude);
    printf("Enter Longitude: ");
    scanf("%f", &b.longitude);
    printf("Enter Timestamp (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", b.timestamp);
    printf("Enter Route: ");
    scanf("%s", b.route);
    
    buses[busCount++] = b;
    printf("Bus location updated successfully!\n");
}

void displayBusLocations() {
    printf("\nReal-Time Bus Locations:\n");
    for (int i = 0; i < busCount; i++) {
        printf("Bus ID: %s, Location: (%.2f, %.2f), Time: %s, Route: %s\n", 
               buses[i].busID, buses[i].latitude, buses[i].longitude, buses[i].timestamp, buses[i].route);
    }
}

void estimateArrivalTime() {
    char busID[10];
    printf("Enter Bus ID to estimate arrival time: ");
    scanf("%s", busID);
    
    for (int i = 0; i < busCount; i++) {
        if (strcmp(buses[i].busID, busID) == 0) {
            printf("Estimated arrival time for Bus %s at the next stop: %d minutes\n", buses[i].busID, rand() % 30 + 5);
            return;
        }
    }
    printf("Bus ID not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Update Bus Location\n2. Display Bus Locations\n3. Estimate Arrival Time\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: updateBusLocation(); break;
            case 2: displayBusLocations(); break;
            case 3: estimateArrivalTime(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}



