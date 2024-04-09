#include <stdio.h>

void readMatrix(int mat[10][10], int rows, int cols);
void displayMatrix(int mat[10][10], int rows, int cols);
void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols);
void subtractMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols);
void multiplyMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows1, int cols1, int cols2);
void multiplyByScaler(int mat[10][10], int scaler, int result[10][10], int rows, int cols);
void divideByScaler(int mat[10][10], int scaler, int result[10][10], int rows, int cols);
void transposeMatrix(int mat[10][10], int result[10][10], int rows, int cols);

int main() {
    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];
    int rowsA, colsA, rowsB, colsB;
    int ch;

    printf("********************\n");
    printf("Select one of the options given below:\n");
    printf("1. Matrix addition.\n");
    printf("2. Matrix subtraction.\n");
    printf("3. Matrix multiplication.\n");
    printf("4. Multiply by a scalar.\n");
    printf("5. Divide by a scalar.\n");
    printf("6. Transpose of a matrix.\n");
    printf("7. Exit.\n");
    printf("********************\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            printf("Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);

            printf("Enter the number of rows and the number of columns for matrix B: ");
            scanf("%d %d", &rowsB, &colsB);

            if (rowsA != rowsB || colsA != colsB) {
                printf("\nMatrices must be of the same size for addition.\n");
                break;
            }

            printf("Enter elements of matrix A:\n");
            readMatrix(matrixA, rowsA, colsA);

            printf("Enter elements of matrix B:\n");
            readMatrix(matrixB, rowsB, colsB);

            printf("Matrix A:\n");
            displayMatrix(matrixA, rowsA, colsA);

            printf("Matrix B:\n");
            displayMatrix(matrixB, rowsB, colsB);

            printf("Result of addition:\n");
            addMatrices(matrixA, matrixB, result, rowsA, colsA);
            displayMatrix(result, rowsA, colsA);
            break;

        case 2:
            printf("Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);

            printf("Enter the number of rows and the number of columns for matrix B: ");
            scanf("%d %d", &rowsB, &colsB);

            if (rowsA != rowsB || colsA != colsB) {
                printf("\nMatrices must be of the same size for subtraction.\n");
                break;
            }

            printf("Enter elements of matrix A:\n");
            readMatrix(matrixA, rowsA, colsA);

            printf("Enter elements of matrix B:\n");
            readMatrix(matrixB, rowsB, colsB);

            printf("Matrix A:\n");
            displayMatrix(matrixA, rowsA, colsA);

            printf("Matrix B:\n");
            displayMatrix(matrixB, rowsB, colsB);

            printf("Result of subtraction:\n");
            subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
            displayMatrix(result, rowsA, colsA);
            break;

        case 3:
            printf("Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);

            printf("Enter the number of rows and the number of columns for matrix B: ");
            scanf("%d %d", &rowsB, &colsB);

            if (colsA != rowsB) {
                printf("\nThe number of columns in matrix A must be equal to the number of rows in matrix B for multiplication.\n");
                break;
            }

            printf("Enter elements of matrix A:\n");
            readMatrix(matrixA, rowsA, colsA);

            printf("Enter elements of matrix B:\n");
            readMatrix(matrixB, rowsB, colsB);

            printf("Matrix A:\n");
            displayMatrix(matrixA, rowsA, colsA);

            printf("Matrix B:\n");
            displayMatrix(matrixB, rowsB, colsB);

            printf("Result of multiplication:\n");
            multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
            displayMatrix(result, rowsA, colsB);
            break;

        case 4:
            printf("Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);

            printf("Enter the scaler: ");
            int scaler;
            scanf("%d", &scaler);

            printf("Enter elements of matrix A:\n");
            readMatrix(matrixA, rowsA, colsA);

            printf("Matrix A:\n");
            displayMatrix(matrixA, rowsA, colsA);

            printf("Result of scalar multiplication:\n");
            multiplyByScaler(matrixA, scaler, result, rowsA, colsA);
            displayMatrix(result, rowsA, colsA);
            break;

        case 5:
            printf("Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);

            printf("Enter the scaler: ");
            scanf("%d", &scaler);

            if (scaler == 0) {
                printf("\nCannot divide by zero.\n");
                break;
            }

            printf("Enter elements of matrix A:\n");
            readMatrix(matrixA, rowsA, colsA);

            printf("Matrix A:\n");
            displayMatrix(matrixA, rowsA, colsA);

            printf("Result of scalar division:\n");
            divideByScaler(matrixA, scaler, result, rowsA, colsA);
            displayMatrix(result, rowsA, colsA);
            break;

        case 6:
            printf("Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);

            printf("Enter elements of matrix A:\n");
            readMatrix(matrixA, rowsA, colsA);

            printf("Matrix A:\n");
            displayMatrix(matrixA, rowsA, colsA);

            printf("Result of transposition:\n");
            transposeMatrix(matrixA, result, rowsA, colsA);
            displayMatrix(result, colsA, rowsA);
            break;

        case 7:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void readMatrix(int mat[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("\t%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("\t%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int rows1, int cols1, int cols2) {
    int i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyByScaler(int mat[10][10], int scaler, int result[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat[i][j] * scaler;
        }
    }
}

void divideByScaler(int mat[10][10], int scaler, int result[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat[i][j] / scaler;
        }
    }
}

void transposeMatrix(int mat[10][10], int result[10][10], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}