#include <stdio.h>

int main() {
    double total_lines = 1000000;  
    double tech_debt = total_lines * 0.1;  
    double reduction_rate = 0.05; 
    int months = 0;

    printf("Month\tTechnical Debt\n");
    while (tech_debt > 0.01 * total_lines) {  
        printf("%d\t%.2f\n", months, tech_debt);
        tech_debt -= tech_debt * reduction_rate;  
        months++;
    }

    printf("\nTechnical debt reduced to manageable levels in %d months.\n", months);
    return 0;
}
