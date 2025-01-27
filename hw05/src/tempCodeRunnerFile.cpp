#include <iostream>
#include <string>
#include <algorithm>

using namespace std; // Внедрение пространства имен std

int countUniqueWords(const string& input) {
    string uniqueWords; // Строка для хранения уникальных слов
    string currWord; // Текущее слово
    size_t pos = 0;

    while ((pos = input.find_first_not_of(" ", pos)) != string::npos) {
        size_t end = input.find_first_of(" ", pos);
        currWord = input.substr(pos, end - pos); // Извлекаем текущее слово

        // Проверяем, содержится ли текущее слово в строке уникальных слов
        if (uniqueWords.find(currWord) == string::npos) {
            // Если не содержится, добавляем его в строку уникальных слов
            if (!uniqueWords.empty()) {
                uniqueWords += " "; // Добавляем пробел перед новым словом
            }
            uniqueWords += currWord;
        }

        pos = end; // Переходим к следующему слову
    }

  
    return count(uniqueWords.begin(), uniqueWords.end(), ' ') + 1;
}

int main() {
    // Пример использования функции countUniqueWords
    string input;
    cout << "Введите строку: ";
    getline(cin, input); // Считываем строку с пробелами

    int uniqueWordsCount = countUniqueWords(input);
    cout << "Количество уникальных слов: " << uniqueWordsCount << endl;

    return 0;
}