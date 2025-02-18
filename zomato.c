#include <stdio.h>

int main()
{
	printf("ZOMATO ORDER TRACKING SYSTEM\n");
	//reading ip from user
	int status;
	while(1) {
		printf("1.Order placed\n2.Preparing Food\n3.Out for delivery\n4.Deliverd\n");
		printf("Enter order status (1-4): ");
		scanf("%d", &status);
		//display corresponding order status
		switch (status) {
		case 1:
			printf("Your order has been placed.\n");
			return 0;
		case 2:
			printf("Your food is being prepared.\n");
			return 0;
		case 3:
			printf("Your order is out for delivery.\n");
			return 0;
		case 4:
			printf("Your order has been delivered. Enjoy your meal!\n");
			return 0;
		default:
			printf("Invalid status. Please enter a number between 1 and 4.\n");
		}
	}
	return 0;
}
