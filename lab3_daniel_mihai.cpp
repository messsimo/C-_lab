#include <iostream>
#include <sstream>
using namespace std;

// Строковая функция
string replaceIngWithEd(const string& sentence) {
    // Разибитие строки на слова
    stringstream ss(sentence);
    string word;
    string result;

    // Цикл и условие
    while (ss >> word) {
        // Проверка на окончание слова
        if (word.size() >= 3 && word.substr(word.size() - 3) == "ing") {
            word = word.substr(0, word.size() - 3) + "ed";  // Замена "ing" на "ed"
        }
        result += word + " ";
    }
    
    // Удаление последнего пробела
    if (!result.empty()) result.pop_back();
    // Возвращение переменной
    return result;
}

int main() {
    // Переменная с текстом
    string sentence = "I am running and swimming in the morning";
    // Передача данных в функцию
    string result = replaceIngWithEd(sentence);
    // Вывод
    cout << "Результат: " << result << endl;
    return 0;
}
