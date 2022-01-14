#include <stdio.h>

int main() {

int dollar20 = 20;
int total20;
int dollar10 = 10;
int total10;
int dollar5 = 5;
int total5;
int dollar1 = 1;
int total1;
int qty;
int totalCash;
double coinHeight;
double coinWeight;

printf("Enter the number of 20s you have: ");
scanf("%d", &qty);
total20 = dollar20 * qty;

printf("Enter the number of 10s you have: ");
scanf("%d", &qty);
total10 = dollar10 * qty;

printf("Enter the number of 5s you have: ");
scanf("%d", &qty);
total5 = dollar5 * qty;

printf("Enter the number of 1s you have: ");
scanf("%d", &qty);
total1 = dollar1 * qty;

totalCash = total20 + total10 + total5 + total1;
coinHeight = (totalCash * 2) / 25.4;
coinWeight = (totalCash * 8.1) / 453.592;

printf("You have $%d in total cash.\n", totalCash);
printf("Your stack of coins is %.2lf inches high.\n", coinHeight);
printf("Your stack of coins weighs %.2lf pounds.\n", coinWeight);

return 0;

}