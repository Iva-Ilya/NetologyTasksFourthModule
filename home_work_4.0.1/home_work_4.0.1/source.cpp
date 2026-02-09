#include <iostream>
#include <Windows.h>
#include <algorithm> // Для использования std::for_each

// Вектор представляет контейнер, который содержит коллекцию объектов одного типа.Для работы с векторами необходимо включить заголовок :
#include <vector>
//

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> numbers = { 4, 7, 9, 14, 12 };

	std::cout << "Входные данные: ";
	for (int i : numbers) {
		std::cout << i << " "; 
	}
	/* Вывод элементов numbers, только c циклом for в классическом виде.
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	} */
	std::cout << std::endl;

	// Лямбда-функция, которая умножает нечетные числа на 3.
	auto multiply = [](int& n) {
		if (n % 2 != 0) { n = n * 3; }	// Проверяем, нечетное ли число и умножаем нечетное число на 3.
		};

	// Используем std::for_each вместо цикла для того, чтобы пройтись по элементам vector numbers и применить к ним лямбда-функцию multiply.
	std::for_each(numbers.begin(), numbers.end(), multiply);

	std::cout << "Выходные данные: ";
	for (int i : numbers) {
		std::cout << i << " ";
	}
	std::cout << std::endl << std::endl << std::endl;

	// Лямбда функция. 
	// Pдесь лямбда-выражение принимает один параметр типа const std::string&, то есть строку, которая выводится на консоль. 
	// И это лямбда-выражение присвоено переменной print.
	// В качестве параметра указана константная ссылка - чтобы не изменять передаваемый параметр и не создавать его копию.
	auto print = [](const std::string& text) {std::cout << text << std::endl; };
	// Вызывая print как стандартную функцию, нужно передать в нее некоторую строку:
	print("Hello");

	std::cout << std::endl;

	// Также можно сразу же при определении вызвать лямбда-выражение, передав в него строку.
	[](const std::string& text) {std::cout << text << std::endl; } ("Hello");

	return 0;
}