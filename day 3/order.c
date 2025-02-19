#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STAGES 5
#define ORDERS 100

int main() {
    srand(time(0));
    double original = 0, optimized = 0;
    
    for (int i = 0; i < ORDERS; i++) {
        double total = 0;
        for (int j = 0; j < STAGES; j++)
            total += (rand() % 5 + 1) + (rand() % 100) / 100.0;
        original += total;
        optimized += total * 0.9;  
    }
    
    printf("Avg Fulfillment Time (Original): %.2f hrs\n", original / ORDERS);
    printf("Avg Fulfillment Time (Optimized): %.2f hrs\n", optimized / ORDERS);
    
    return 0;
}

