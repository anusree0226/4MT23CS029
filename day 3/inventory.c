#include <stdio.h>

#define WAREHOUSES 10
#define PRODUCTS 5

int calculateWarehouseValue(int values[], int size) {
    int warehouse_value = 0;
    for (int i = 0; i < size; i++) warehouse_value += values[i];
    return warehouse_value;
}

int main() {
    int values[PRODUCTS] = {60, 100, 120, 80, 90};
    int total = 0;
    
    for (int i = 0; i < WAREHOUSES; i++) {
        int warehouse_value = calculateWarehouseValue(values, PRODUCTS);
        printf("Warehouse %d inventory value: %d\n", i + 1, warehouse_value);
        total += warehouse_value;
    }
    
    printf("Total inventory value: %d\n", total);
    return 0;
}
