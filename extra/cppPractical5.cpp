// cppPractical5.cpp

#include <iostream>
using namespace std;


void allocateMatrix(int*** arr, int rows, int cols)
{
    *arr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        (*arr)[i] = new int[cols];
    }
}

void freeMatrix(int** arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
void multiplyMatrices(int** A, int** B, int** result, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
	cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
	}
}

// you can also do it this way...
void allocateMatrixContiguous(int*** arr, int rows, int cols)
{
    *arr = new int* [rows];
    (*arr)[0] = new int[rows * cols];

    for (int i = 1; i < rows; i++)
    {
        (*arr)[i] = (*arr)[0] + i * cols;
    }
}

void freeMatrixContiguous(int** arr)
{
    delete[] arr[0];
    delete[] arr;
}

void calcNextRow(const int* prevRow, int* nextRow, int rowNo)
{
    nextRow[0] = 1;
	for (int j = 1; j < rowNo; j++)
    {
        nextRow[j] = prevRow[j - 1] + prevRow[j];
	}
	nextRow[rowNo] = 1;

}

void printRow(const int* row, int rowNo, int n)
{
    for (int j = 0; j <= rowNo; j++)
    {
        cout << row[j] << " ";
    }
    cout << endl;
}

void pascalTriangle(int n) 
{
    int* prevRow = new int[n];
    int* nextRow = new int[n];

    prevRow[0] = 1;
    printRow(prevRow, 0, n);

    for (int rowNo = 1; rowNo < n; rowNo++)
    {
        calcNextRow(prevRow, nextRow, rowNo);
        printRow(nextRow, rowNo, n);
        
        int* temp = prevRow;
        prevRow = nextRow;
        nextRow = temp;
	}
    delete[] prevRow;
    delete[] nextRow;
}

int main()
{
	//exercise 1
    int n = 10;
    pascalTriangle(n);

	cout << " " << endl;

    //exercise 2
    int** matrix1;
    int** matrix2;

    allocateMatrix(&matrix1, 3, 4);
    matrix1[0][0] = 1;
    matrix1[2][3] = 12;
    freeMatrix(matrix1, 3);

    allocateMatrixContiguous(&matrix2, 3, 4);
    matrix2[0][0] = 1;
    matrix2[2][3] = 12;
    freeMatrixContiguous(matrix2);


    // A x B = C
	int N = 3;
    int** matrixA;
    int** matrixB;
    int** matrixC;

    allocateMatrix(&matrixA, N, N);
    allocateMatrix(&matrixB, N, N);
    allocateMatrix(&matrixC, N, N);

	// yes this is ridiculous and you should use an initialiser function
    // but it is good just to show how to assign values
    // plus it is very clear!
    matrixA[0][0] = 1; matrixA[0][1] = 2; matrixA[0][2] = 3;
    matrixA[1][0] = 4; matrixA[1][1] = 5; matrixA[1][2] = 6;
    matrixA[2][0] = 7; matrixA[2][1] = 8; matrixA[2][2] = 9;

    matrixA[0][0] = 1; matrixA[0][1] = 2; matrixA[0][2] = 3;
    matrixA[1][0] = 4; matrixA[1][1] = 5; matrixA[1][2] = 6;
    matrixA[2][0] = 7; matrixA[2][1] = 8; matrixA[2][2] = 9;


    multiplyMatrices(matrixA, matrixB, matrixC, N);
    freeMatrix(matrixA, N);
    freeMatrix(matrixB, N);
    freeMatrix(matrixC, N);

    return 0;
}