#include <stdio.h>
#include <string.h>

int main() {

    char word[100];
    char consonant[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    while (1) {
        printf("Enter a string: ");
        scanf("%s", word);
        if (strcmp(word,  "stop") == 0) {
            break;
        }
        for (int i = 0; i < strlen(word); i++) {
            for (int j = 0; j < strlen(consonant); j++) {
            if (word[i] == consonant[j]) {
                printf("%c", word[i]);
            }
        }
    }
    printf("\n");
  }
  return 0;
}
