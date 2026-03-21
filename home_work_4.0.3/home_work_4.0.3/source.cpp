#include <iostream>
#include <Windows.h>
#include <vector>
#include <functional>
#include <cmath>
#include <iomanip>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    // Массив углов в радианах
    std::vector<float> angles = { 0, (3.14 / 6), (3.14 / 4), (3.14 / 3), (3.14 / 2), 3.14 };

    // Контейнер для хранения операций (лямбда-функций)
    std::vector<std::function<void(float)>> functions;

    // 1. Добавляем операцию вычисления синуса
    functions.push_back([](float angle) {
        std::cout << " sin=" << std::setprecision(3) << std::sin(angle);
        });

    // 2. Добавляем операцию вычисления косинуса
    functions.push_back([](float angle) {
        std::cout << " cos=" << std::setprecision(3) << std::cos(angle);
        });

    std::cout << "Входные данные:  ";
    for (float i : angles) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    // Вывод результатов
    std::cout << "Синусы и косинусы углов:" << std::endl;
    for (const auto& angle : angles) {
        std::cout << angle << ":";
        for (const auto& function : functions) {
            function(angle);
        }
        std::cout << std::endl;
    }

    return 0;
}