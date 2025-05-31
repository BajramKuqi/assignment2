#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 1000
#define PASSWORD_LEN 9 

int main() {
    int n;
    char passwords[MAX_PASSWORDS][PASSWORD_LEN];
    int count = 0;
    printf("Enter the number of passwords: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_PASSWORDS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_PASSWORDS);
        return 1;
    }

    srand((unsigned)time(NULL));  

    while (count < n) {
        char pwd[PASSWORD_LEN];

        for (int i = 0; i < 3; i++) {
            pwd[i] = 'A' + (rand() % 26);
        }

        for (int i = 3; i < 6; i++) {
            pwd[i] = 'a' + (rand() % 26);
        }

        for (int i = 6; i < 8; i++) {
            pwd[i] = '0' + (rand() % 10);
        }

        pwd[8] = '\0'; 
        int unique = 1;
        for (int j = 0; j < count; j++) {
            if (strcmp(passwords[j], pwd) == 0) {
                unique = 0;
                break;
            }
        }

        if (unique) {
            strcpy(passwords[count], pwd);
            count++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", passwords[i]);
    }

    return 0;
}
