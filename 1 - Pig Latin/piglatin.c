#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pig.c"

int main() { 
    char input[100];
    while (1) {

        // Take in input
        printf("Enter an input: ");
        fgets(input, sizeof(input), stdin);

        // Stop program if empty input is provided
        if (strcmp(input, "\n") == 0) {
            break;
        }

        if (strlen(input) >= 50) {
            printf("Input too long. Please enter a shorter input.\n");
            while (fgets(input, sizeof(input), stdin)) {
                if (strlen(input) < 50) {
                    break;
                }
                printf("Input too long. Please enter a shorter input.\n");
            }
        }

        input[strcspn(input, "\n")] = '\0';     

        // Apply "pig" to each word
        char *token = strtok(input, " ");
        char temp[1000];
        char output[1000] = "";

        while(token != NULL ) {
            memcpy(temp, token, 100);
            strcat(output, pig(temp));
            strcat(output, " ");
            token = strtok(NULL, " ");
        }
        printf( "%s\n", output ); 

    }
    return 0;
}