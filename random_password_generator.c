/*
* gcc -o random_password_generator random_password_generator.c
* ./random_password_generator
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int main() 
{
    printf("##############################\n");
    printf("NIST Special Publication 800-63B (Recommended Password Policy characteristics):\n");
    printf("1. Length: Minimum of 8 characters, preferably longer.\n");
    printf("2. Complexity: Avoid overly complex rules; encourage passphrases.\n");
    printf("3. Composition: Allow any characters, including spaces and emojis.\n");
    printf("4. Dictionary Checks: Avoid easily guessable words or phrases.\n");
    printf("5. Expiry: Avoid password expiration policies unless necessary.\n");
    printf("6. Blacklist: Implement a blacklist of commonly used passwords.\n");
    printf("7. Authentication Assurance: Use multi-factor authentication (MFA) for added security.\n");
    printf("##############################\n");
    printf("Password Length:");

    int length;
    scanf("%d", &length);
    
    if (length < 8)
    {
        printf("Password Length must be greater than >= 8!");
        return 1;
    }

    char*password = malloc(length + 1);

    char*uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int uppers_length = strlen(uppers);

    char*lowers = "abcdefghijklmnopqrstuvwxyz";
    int lowers_length = strlen(lowers);

    char*digits = "0123456789";
    int digits_length = strlen(digits);

    char*symbols = "!@#$%^&*()_+-={}[]:<>,.?~`";
    int symbols_length = strlen(symbols);

    srand(time(NULL) * getpid());

    for (int i = 0; i < length; i++)
    {
        int char_type = rand() % 4;
        
        if (char_type == 0)
            password[i] = uppers[rand() % uppers_length];
        else if (char_type == 1)
            password[i] = lowers[rand() % lowers_length];
        else if (char_type == 2)
            password[i] = digits[rand() % digits_length];
        else
            password[i] = symbols[rand() % symbols_length];
        
    }
    password[length] = '\0';

    printf("Password: %s\n", password);

    free(password);

    return 0;

}