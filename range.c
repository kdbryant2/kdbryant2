#include <stdio.h>
#include <stdlib.h>
/*This program looks at all the command line arguments that are always real numbers and prints the range of these numbers. 
Recall the range is the difference between the maximum and the minimum. If there are no command line arguments, print out
an error message and return. Two executions of the program are shown below. Use the double datatype. */

int main(int argc, char* argv[]) {
    
    if (argc == 1 ) {
        printf("This program requires at least one argument");
        //return -1;
    }
    else {
        double max = atof(argv[1]);
        double min = atof(argv[1]);

        for (int i = 1; i < argc; i++) {
            if (atof(argv[i]) > max) {
                max = atof(argv[i]);
            }
            if (atof(argv[i]) < min) {
                min = atof(argv[i]);
            }
        }
        printf("The range of these %d values is %lf", (argc - 1), (max - min));
    }

    return 0;
}