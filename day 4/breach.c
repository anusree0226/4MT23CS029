#include <stdio.h>
#include <string.h>
#include <ctype.h>


const char* check_password_strength(char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

   
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (ispunct(password[i])) has_special = 1;
    }

    
    if (length < 8) return "Weak";
    if (has_upper && has_lower && has_digit && has_special) return "Strong";
    if (has_lower && has_digit) return "Moderate";
    return "Weak";
}

int main() {
    FILE *file = fopen("credentials.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100], username[50], password[50];

   
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^:]:%s", username, password); 

        printf("User: %s, Password: %s\n", username, password);
        printf("Password Strength: %s\n", check_password_strength(password)); 
        printf("\n");
    }

    fclose(file);  
    return 0;
}
