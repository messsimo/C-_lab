#include <iostream>
using namespace std;

// Функция
int findNumbers(int arr[], int size) {
    // Изначальные значения
    int count = 0;
    int max_value = arr[0];
    
    // Цикл с уловие для выявления значений
    for (int i = 0; i < size; i++) {
        if (arr[i] >= max_value) {
            count++;
            max_value = arr[i];
        }
    }
    // Возвращение переменной
    return count;
}

int main() {
    // Длина массива и его значения
    const int size = 7;
    int arr[size] = {1, 2, 2, 1, 3, 5, 4};

    // Вызов функции и передача в нее значений
    int result = findNumbers(arr, size);
    // Вывод значений в терминал
    cout << "Количество элементов, которые не меньше всех предыдущих: " << result << endl;
    return 0;
}