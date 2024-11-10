#include <iostream>
#include <map>
using namespace std;

// Функция для поиска максимального элемента, встречающегося более одного раза
int findMaxRepeated(int** matrix, int rows, int cols) {
    map<int, int> frequency;

    // Подсчет частоты каждого элемента
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            frequency[matrix[i][j]]++;
        }
    }

    // Поиск максимального элемента, который встречается более одного раза
    int maxRepeated = INT_MIN;
    bool found = false;

    for (const auto& elem : frequency) {
        if (elem.second > 1 && elem.first > maxRepeated) {
            maxRepeated = elem.first;
            found = true;
        }
    }

    // Если не найдено ни одного повторяющегося элемента, вернуть специальное значение
    return found ? maxRepeated : -1;
}

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    // Динамическое выделение памяти для матрицы
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Поиск максимального элемента, встречающегося более одного раза
    int result = findMaxRepeated(matrix, rows, cols);
    if (result != -1) {
        cout << "Максимальный элемент, встречающийся более одного раза: " << result << endl;
    } else {
        cout << "Повторяющихся элементов нет." << endl;
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}