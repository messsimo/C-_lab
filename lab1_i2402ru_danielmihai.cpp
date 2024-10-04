#include <iostream>
#include <set>
#include <tuple>      // Это нужно для использования tuple
#include <algorithm>
#include <utility>    // Это нужно для make_tuple


using namespace std;  // Стандартное пространство имен

int main() {
    int n;  // Переменная с числом пользователя
    cout << "Введите число n: ";
    cin >> n;  // Считывание значение n

    // Проверка числа n
    if (n < 3) {
        cout << "Введите число от 3-х!" << endl;
        return 1;  // Завершение программы
    }

    // Множество для хранения тройк
    set<tuple<int, int, int> > combinatii_unice;  // Пробел между '>' и '>' исправлен

    // Перебор всех значений i от 1 до n-3 (первый цикл)
    for (int i = 1; i < n - 2; ++i) {
        // Перебор значения j от i+1 до n-2 (второй цикл)
        for (int j = i + 1; j < n - 1; ++j) {
            // Перебор значения k от j+1 до n-1 (третий цикл)
            for (int k = j + 1; k < n; ++k) {
                // Добавляем значения в кортеж (tuple)
                combinatii_unice.insert(make_tuple(i, j, k));
            }
        }
    }

    // Вывод всех комбинаций из кортежа через перебор кортежа
    for (const auto& comb : combinatii_unice) {
        // Переменные с данными из кортежа
        int i = get<0>(comb);
        int j = get<1>(comb);
        int k = get<2>(comb);
        
        // Проверка условия Пифагора
        if (i * i + j * j == k * k) { 
            // Выводим значения
            cout << i << " " << j << " " << k << endl;
        }
    }

    // Завершение программы
    return 0;
}