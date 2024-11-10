#include <iostream>
using namespace std;

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функция для вычисления суммы элементов столбца
int sumColumn(int** matrix, int rows, int colIndex) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += matrix[i][colIndex];
    }
    return sum;
}

// Функция для поиска столбца с максимальным элементом
int findMaxColumn(int** matrix, int rows, int cols) {
    int maxElement = matrix[0][0];
    int maxColIndex = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxColIndex = j;
            }
        }
    }
    return maxColIndex;
}

int main() {
    // Инициализация первой матрицы (3x3)
    int matrix1_data[3][3] = {
        {3, 5, 1},
        {2, 4, 7},
        {9, 6, 0}
    };
    int* matrix1[3];
    for (int i = 0; i < 3; ++i) {
        matrix1[i] = matrix1_data[i];
    }

    // Инициализация второй матрицы (3x4)
    int matrix2_data[3][4] = {
        {8, 2, 3, 4},
        {1, 5, 6, 7},
        {4, 8, 9, 1}
    };
    int* matrix2[3];
    for (int i = 0; i < 3; ++i) {
        matrix2[i] = matrix2_data[i];
    }

    // Инициализация третьей матрицы (4x2)
    int matrix3_data[4][2] = {
        {5, 9},
        {3, 2},
        {8, 1},
        {7, 4}
    };
    int* matrix3[4];
    for (int i = 0; i < 4; ++i) {
        matrix3[i] = matrix3_data[i];
    }

    // Поиск столбцов с максимальными элементами и вычисление их суммы
    int colIndex1 = findMaxColumn(matrix1, 3, 3);
    int colIndex2 = findMaxColumn(matrix2, 3, 4);
    int colIndex3 = findMaxColumn(matrix3, 4, 2);

    int sum1 = sumColumn(matrix1, 3, colIndex1);
    int sum2 = sumColumn(matrix2, 3, colIndex2);
    int sum3 = sumColumn(matrix3, 4, colIndex3);

    // Вывод матриц и результатов
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1, 3, 3);
    cout << "Сумма элементов в коллонке " << colIndex1 << ": " << sum1 << endl << endl;

    cout << "Matrix 2:" << endl;
    printMatrix(matrix2, 3, 4);
    cout << "Сумма элементов в коллонке " << colIndex2 << ": " << sum2 << endl << endl;

    cout << "Matrix 3:" << endl;
    printMatrix(matrix3, 4, 2);
    cout << "Сумма элементов в коллонке " << colIndex3 << ": " << sum3 << endl << endl;

    // Итоговая сумма
    int totalSum = sum1 + sum2 + sum3;
    cout << "Общая сумма всех коллонок " << totalSum << endl;

    return 0;
}