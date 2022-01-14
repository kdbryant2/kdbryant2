#include <stdio.h>
#include <string.h>

void countCase(char str[], int *pNumUpper, int *pNumLower); 

int main() {

    char word[50];
    int upper, lower;

    while (scanf("%s", &word) == 1) {
        countCase(word, &upper, &lower);
        printf("%s: %d uppercase, %d lowercase\n", word, upper, lower);
    }
    
    return 0;
}
void countCase(char str[], int *pNumUpper, int *pNumLower) {
    *pNumUpper = 0;
    *pNumLower = 0;

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            *pNumUpper = *pNumUpper + 1;
        }
        if (c >= 'a' && c <= 'z') {
            *pNumLower = *pNumLower + 1;
        }
    }
}