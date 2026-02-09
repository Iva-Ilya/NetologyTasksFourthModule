#include <iostream>
#include <Windows.h>
#include <variant> // Для использования std::variant
#include <vector>



std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}








int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::variant result = get_variant();

    // 1.Используем std::get<int>(result)

    if (result.index() == 0) {
        int value = std::get<int>(result);
        std::cout << "Результат int. Умножим на 2 " << value * 2 << std::endl;
    }
    else if (result.index() == 1) {
        std::string str = std::get<std::string>(result);
        std::cout << "Результат std::string. " << str << std::endl;
    }
    else if (result.index() == 2) {
        std::vector<int> numbers = std::get<std::vector<int>>(result);
        std::cout << "Результат std::vector<int> ";
        for (int i : numbers) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl << std::endl;

    // 2.Используем std::get_if (без исключений)
    if (int* int_value = std::get_if<int>(&result)) {
        std::cout << "Результат int. Умножим на 2 " << *int_value << std::endl;
    }
    // Пытаемся получить string
    else if (std::string* str_value = std::get_if<std::string>(&result)) {
        std::cout << "Результат std::string. " << *str_value << std::endl;
    }
    // Пытаемся получить vector
    else if (std::vector<int>* vec_value = std::get_if<std::vector<int>>(&result)) {
        std::cout << "Результат std::vector<int> ";
        for (int num : *vec_value) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }



    //

	return 0;
}