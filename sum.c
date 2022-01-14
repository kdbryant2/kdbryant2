#include <stdio.h>
#include <string.h>

int sumDigits(int num) {
    int answer = 0;
    while (num > 0) {
        answer += num % 10;
        num /= 10;
    }
    return answer;
}

int countDigits(int n) {
    int count = 0;
    if (n == 0) {
        return 0;
    }
    /*if (n > 0) {
        count++;
        countDigits(n / 10);
    } this doesn't work*/
    return 1 + countDigits(n / 10);
}

int countSevens(int n) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == 7) {

    return 1 + countSevens(n / 10);
    }
    
    return 0 + countSevens(n / 10);
}

int countChar(char str[], int index) {
    if (str[index] == '\0') {
        return 0;
    }
    return (1 + countChar(str, index + 1));
}

int sumArray(int *arr, int size) {
    if (size == 1) {
        return arr[0];
    }
    return arr[size - 1] + sumArray(arr, size - 1);
}
int main() {

    int num[100];
    char str[50];

    /*printf("Enter an integer to compute the sum of its digits: ");
    scanf("%d", &num);

    printf("Enter a string: ");
    scanf("%s", str);

    printf("sumDigits(%d) = %d\n", num, sumDigits(num));
    printf("Number of digits is %d\n", countDigits(num));
    printf("Number of sevens is %d\n", countSevens(num));

    printf("Number of characters in %s is %d\n", str, countChar(str, 0));*/
    
    int array[] = {3, 8, 5, 1, 2, 12, 7, 4};
    int size = 8;

    int sum = sumArray(array, size);
    printf("Sum of the array is %d\n", sum);

    /*int numbers;32q3w4
    printf("How many numbers do you want to enter?: ");
    scanf("%d", &numbers);
    printf("Enter %d numbers: ", numbers);
    for (int i = 0; i < numbers; i++) {
        scanf("%d", &num[i]);
    }
    int largest = num[0];
    for (int i = 0; i < numbers; i++) {
        if (num[i] > largest) {
            largest = num[i];
        }
    }
    printf("The largest number is %d\n", largest);*/

return 0;
}