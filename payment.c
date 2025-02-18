#include <stdio.h>
#include <string.h>

int main() {
	int paymentMethod, bankChoice;
	char cardNumber[17];
	char upiID[50];
	while(1) {
		printf("PAYMENT GATEWAY SIMULATION\n");
		printf("Select Payment Method (1-3):\n");
		printf("1. Credit/Debit Card\n2. UPI\n3. Net Banking\n");
		scanf("%d", &paymentMethod);

		switch (paymentMethod) {
		case 1:
			printf("Enter your 16-digit card number: ");
			scanf("%16s", cardNumber);
			if (strlen(cardNumber) == 16) {
				printf("Payment Successful!\n");
			} else {
				printf("Transaction Failed. Please try again.\n");
			}
			return 0;

		case 2:
			printf("Enter your UPI ID: ");
			scanf("%s", upiID);
			if (strchr(upiID, '@') != NULL) {
				printf("Payment Successful!\n");
			} else {
				printf("Transaction Failed. Please try again.\n");
			}
			return 0;

		case 3:
			printf("Select Bank:\n1. SBI\n2. HDFC\n");
			scanf("%d", &bankChoice);
			if (bankChoice == 1 || bankChoice == 2) {
				printf("Payment Successful!\n");
			} else {
				printf("Transaction Failed. Please try again.\n");
			}
			return 0;

		default:
			printf("Invalid payment method. Please try again.\n");
		}
	}

	return 0;
}
