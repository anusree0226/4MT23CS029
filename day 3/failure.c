#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_RECOMMENDATIONS 100
#define FAILURE_PROBABILITY 0.02
int main() {
    int failed_recommendations = 0;
    srand(time(NULL)); 
 for (int i = 0; i < TOTAL_RECOMMENDATIONS; i++) {
        double random_value = (double)rand() / RAND_MAX; 
        if (random_value < FAILURE_PROBABILITY) {
            failed_recommendations++;
        }
    }
     printf("Total failed recommendations: %d out of %d\n", failed_recommendations, TOTAL_RECOMMENDATIONS);
  return 0;
}
