#include <stdio.h>
#include <string.h>

int countVowels(char str[]);

int main() {

    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    int count = countVowels(word);

    printf("There are %d vowels in %s", count, word);

    return 0;
}
int countVowels(char str[]) {
    char vowels[] = "aeiouAEIOU";
    int count;
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(vowels); j++) {
            if (str[i] == vowels[j]) {
                count++;
            }
        }
    }
    return count;
}