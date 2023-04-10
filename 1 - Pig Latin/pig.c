#include <stdio.h>
#include <string.h>
#include "pig.h"

char *pig(char *word) {

    if (strlen(word) < 3) return word;
    const char *vowels = "aeiouAEIOU";
    char firstChar = *word;

    // Case 1: Word start wirh vowel
    if (strchr(vowels, firstChar)) {
        // Add "way" to word
        return strcat(word, "way");
    } 
    
    // Case 2: Word starts with consonant
    else {
        char firstConsonants[3] = "";
        int i;

        // Get first consonant letter(s)
        for (i = 0; i < strlen(word) - 1; i++) {
            if (strchr(vowels, word[i]) || word[i] == 'y' || word[i] == 'Y') {
                if (firstChar == 'y' || firstChar == 'Y') {
                    firstConsonants[i] = word[i];
                }
                firstConsonants[i+1] = '\0';
                break;
            }
            firstConsonants[i] = word[i];
        }

        // Remove consonant(s) from beginning of word
        int len_word = strlen(word);
        int len_con = strlen(firstConsonants);

        for (i = 0; i < len_word - len_con; i++) {
            word[i] = word[i + len_con];
        }

        // Add consonant(s) to end of word + "ay"
        for (i = 0; i < len_con; i++) {
            word[len_word - len_con + i] = firstConsonants[i];
        }
        strcat(word, "ay");
        return word;
    }
}
