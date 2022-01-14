#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols)
{
  int **matrix = malloc(sizeof(int *) * numRows);
  for (int r = 0; r < numRows; r++)
  {
    matrix[r] = malloc(sizeof(int) * numCols);
  }
  return matrix;
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
  for (int r = 0; r < numRows; r++)
  {
    for (int c = 0; c < numCols; c++)
    {
      fscanf(fp, "%d", &matrix[r][c]);
    }
  }
}

void printMatrix(int **matrix, int numRows, int numCols);

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[1], "r");

  int **matrix;
  int numRows, numCols;
  fscanf(fp, "%d%d", &numRows, &numCols);
  matrix = allocateMatrix(numRows, numCols);
  readMatrix(fp, matrix, numRows, numCols);

  printMatrix(matrix, numRows, numCols);

  return 0;
}

void printMatrix(int **matrix, int numRows, int numCols)
{
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      if (matrix[i][j] % 3 == 0 && matrix[i][j] % 5 == 0)
      {
        printf(" Hammer");
      }
      else if (matrix[i][j] % 3 == 0)
      {
        printf(" Rammer");
      }
      else if (matrix[i][j] % 5 == 0)
      {
        printf(" Jammer");
      }
      else
      {
        printf(" %d", matrix[i][j]);
      }
    }
    printf("\n");
  }
}
