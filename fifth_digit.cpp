#include <iostream>
#include <vector>
#include <algorithm> // Для std::swap

// Функция для вставки числа в вектор, если оно меньше максимального элемента
void insertItem(std::vector<int>& vec, int val) {
    // Если вектор ещё не содержит 5 элементов или новое число меньше максимального
    if (vec.size() < 5 || val < vec[4]) {
        // Вставляем число в вектор
        for (size_t i = 0; i < vec.size(); i++) {
            if (val <= vec[i]) {
                std::swap(vec[i], val); // Обмениваем значения
            }
        }
        // Если вектор ещё не заполнен, добавляем новое значение
        if (vec.size() < 5) {
            vec.push_back(val);
        }
    }
}

// Функция для вывода пятого по возрастанию числа
void printFifthSmallest(const std::vector<int>& vec) {
    if (vec.size() < 5) {
        std::cerr << "Error: Not enough numbers entered to determine the fifth smallest." << std::endl;
    } else {
        std::cout << "Fifth smallest number: " << vec[4] << std::endl;
    }
}

int main() {
    std::vector<int> smallestNumbers; // Вектор для хранения пяти наименьших чисел
    int input;

    std::cout << "Enter numbers. Enter -1 to display the fifth smallest number or -2 to exit." << std::endl;

    while (true) {
        std::cout << "--> ";
        std::cin >> input;

        // Проверка на корректность ввода
        if (std::cin.fail()) {
            std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(INT_MAX, '\n'); // Игнорирование некорректного ввода
            continue;
        }

        // Обработка команд
        if (input == -1) {
            printFifthSmallest(smallestNumbers);
        } else if (input == -2) {
            std::cout << "Exiting the program." << std::endl;
            break;
        } else {
            insertItem(smallestNumbers, input);
        }
    }

    return 0;
}