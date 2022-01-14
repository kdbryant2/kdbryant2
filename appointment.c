#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

char userInput[1000];
char name[50];
char building[50];
char date[50];
char time[50];
int array[5] = {0, 0, 0, 0};
int c = 1;
int d = 0;
int e = 0;
// Kaitlyn Bryant. This program takes input from a user and formats it into an appointment based on scanning patterns for name, time, date and building.
scanf("%s", userInput);

while (!feof(stdin)) {
    for (int i = 0; i < strlen(userInput); i++) {
        c = 1;
        if (isupper(userInput[0]) && isupper(userInput[1]) && isupper(userInput[2]) && (isupper(userInput[3]) || isdigit(userInput[3])) && strlen(userInput) >= 6) {
            for (int b = 4; b < strlen(userInput); b++) {
                if (!(isdigit(userInput[b]))) {
                    c = 0;
                    //strcpy(building, "<not provided>");
                }
            }
            if (c == 1) {
            strcpy(building, userInput);
            array[0] = 1;
            }
        }
        if (isupper(userInput[i])) {
            int a = 1;
            for (int j = 1; j < strlen(userInput); j++) {
                if (!(islower(userInput[j]))) {
                a = 0;
                }
            }
            if (a == 1) {
                strcpy(name, userInput);
                array[1] = 1;
            }
        }
        if (isdigit(userInput[0]) && isdigit(userInput[1]) && userInput[2] == '-' && (isdigit(userInput[3])) && isdigit(userInput[4]) && strlen(userInput) == 5) {
            d = 1;
            strcpy(date, userInput);
        }
        if (isdigit(userInput[0]) && userInput[0] != '0') {
            if (isdigit(userInput[1]) && (userInput[2] == 'a' || userInput[2] == 'p') && userInput[3] == 'm' && strlen(userInput) == 4) {
                e = 1;
                strcpy(time, userInput);
            }
            else if ((userInput[1] == 'a' || userInput[1] == 'p') && userInput[2] == 'm' && strlen(userInput) == 3) {
                e = 1;  
                strcpy(time, userInput);
            }
        }
    }
    scanf("%s", userInput);
}
if (d == 0) {
    strcpy(date, "<not provided>");
}
if (array[0] == 0) {
    strcpy(building, "<not provided>");
}
if (array[1] == 0) {
    strcpy(name, "<not provided>");
}
if (e == 0) {
    strcpy(time, "<not provided>");
}
printf("Appointment with %s is on %s at %s in %s\n", name, date, time, building);
    

    return 0;
}
