#include <iostream>
#include <cmath>

// Функция для вычисления синуса через степенной ряд
double sin_approx(double x, int terms) {
    // Изначальное значение
    double result = 0.0;
    // Цикл
    for (int k = 0; k < terms; ++k) {
        double term = pow(-1, k) * pow(x, 2 * k + 1) / tgamma(2 * k + 2); // (2k+1)!
        result += term;
    }
    return result;
}

int main() {
    // Переменные
    double x;
    int terms;

    // Ввод значения x и количества членов ряда
    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите количество членов ряда для приближения: ";
    std::cin >> terms;

    // Нахождение стандартного синуса
    double sin_value = std::sin(x);

    // Нахождение синуса через степянной ряд 
    double sin_series_value = sin_approx(x, terms);

    // Вывод результатов
    std::cout << "Стандартный синус: " << sin_value << std::endl;
    std::cout << "Приближённый синус: " << sin_series_value << std::endl;

    return 0;
}