#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Merge(int numbers[], int i, int j, int k)
{
    int mergedSize; // Size of merged partition
    int mergePos;   // Position to insert merged number
    int leftPos;    // Position of elements in left partition
    int rightPos;   // Position of elements in right partition
    int *mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i;                         // Initialize left partition position
    rightPos = j + 1;                    // Initialize right partition position
    mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary array
                                         // for merged numbers

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k)
    {
        if (numbers[leftPos] < numbers[rightPos])
        {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else
        {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j)
    {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k)
    {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos)
    {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    delete[] mergedNumbers;
}

void MergeSort(int numbers[], int i, int k)
{
    int j;

    if (i < k)
    {
        j = (i + k) / 2; // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}
void Merge(string arr[], int i, int j, int k)
{
    int mergedSize; // Size of merged partition
    int mergePos;   // Position to insert merged number
    int leftPos;    // Position of elements in left partition
    int rightPos;   // Position of elements in right partition
    string *mergedArr = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i;                        // Initialize left partition position
    rightPos = j + 1;                   // Initialize right partition position
    mergedArr = new string[mergedSize]; // Dynamically allocates temporary array
                                        // for merged numbers

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k)
    {
        if (arr[leftPos] < arr[rightPos])
        {
            mergedArr[mergePos] = arr[leftPos];
            ++leftPos;
        }
        else
        {
            mergedArr[mergePos] = arr[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j)
    {
        mergedArr[mergePos] = arr[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k)
    {
        mergedArr[mergePos] = arr[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos)
    {
        arr[i + mergePos] = mergedArr[mergePos];
    }
    delete[] mergedArr;
}

void MergeSort(string arr[], int i, int k)
{
    int j;

    if (i < k)
    {
        j = (i + k) / 2; // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(arr, i, j);
        MergeSort(arr, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(arr, i, j, k);
    }
}

int main(int argc, char *argv[])
{
    if (argv[1][0] == 'i')
    {
        fstream input1;
        fstream input2;

        input1.open(argv[2]);
        input2.open(argv[3]);

        int *one = new int[20000];
        int *two = new int[20000];

        int one_size = 0;
        int two_size = 0;

        string input;
        int value;
        while (input1 >> value)
        {
            one[one_size] = value;
            one_size++;
        }
        while (input2 >> value)
        {
            two[two_size] = value;
            two_size++;
        }
        MergeSort(one, 0, one_size - 1);
        MergeSort(two, 0, two_size - 1);
        //for(int i = 0; i < one_size; i++) { cout << i << ": " << one[i] << endl; }
        //for(int i = 0; i < two_size; i++) { cout << i << ": " << two[i] << endl; }
        int one_index = 0;
        int two_index = 0;

        int lastPrintedIndex = -1;
        while (one_index < one_size && two_index < two_size)
        {
            if (one[one_index] == two[two_index])
            {
                if (lastPrintedIndex == -1 || one[lastPrintedIndex] != one[one_index])
                {
                    cout << one[one_index] << endl;
                    lastPrintedIndex = one_index;
                }

                one_index++;
                two_index++;
            }
            else if (one[one_index] < two[two_index])
            {
                one_index++;
            }
            else
            {
                two_index++;
            }
        }
    }
    else
    {
        fstream input1;
        fstream input2;

        input1.open(argv[2]);
        input2.open(argv[3]);

        string *one = new string[20000];
        string *two = new string[20000];

        int one_size = 0;
        int two_size = 0;

        string input;
        string value;
        while (input1 >> value)
        {
            one[one_size] = value;
            one_size++;
        }
        while (input2 >> value)
        {
            two[two_size] = value;
            two_size++;
        }
        MergeSort(one, 0, one_size - 1);
        MergeSort(two, 0, two_size - 1);
        //for(int i = 0; i < one_size; i++) { cout << i << ": " << one[i] << endl; }
        //for(int i = 0; i < two_size; i++) { cout << i << ": " << two[i] << endl; }
        int one_index = 0;
        int two_index = 0;

        int lastPrintedIndex = -1;
        while (one_index < one_size && two_index < two_size)
        {
            if (one[one_index] == two[two_index])
            {
                if (lastPrintedIndex == -1 || one[lastPrintedIndex] != one[one_index])
                {
                    cout << one[one_index] << endl;
                    lastPrintedIndex = one_index;
                }

                one_index++;
                two_index++;
            }
            else if (one[one_index] < two[two_index])
            {
                one_index++;
            }
            else
            {
                two_index++;
            }
        }
    }
    return 0;
}