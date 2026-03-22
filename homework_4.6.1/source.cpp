#include <iostream>
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

/* STL(standart template library, стандартная библиотека шаблонов) — набор обобщённых алгоритмов,
контейнеров, средств доступа к их содержимому и различных вспомогательных функций в C++. */

/*
STL разделяют на 4 блока:
1)Контейнеры;
2)Алгоритмы;
3)Итераторы;
4)Функторы;
*/





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
	Библиотека контейнеров является универсальной коллекцией шаблонов классов и алгоритмов, позволяющих программистам легко реализовывать общие
	структуры данных, такие как очереди, списки и стеки.
	*/
	/*
	Контейнеры разделят на 4 вида:
	- Последовательные;
	- Ассоциативные;
	- Неупорядоченные ассоциативные;
	- Адаптеры;
	*/

	std::string text = "Hello world!";

	// Словарь для подсчета частоты символов
	std::map<char, int> frequency;

	// Подсчитываем частоту каждого символа
	for (char c : text) {
		frequency[c]++;
	}
	
	int count = 0;
	int i = 0;
	for (char c : text) {
		std::cout << frequency[c] << " ";
		std::cout << "count " << count << std::endl;
		count++;
		std::cout << frequency[i] << count << std::endl;
		i++;
	}

	for (const auto& pair : frequency) {
		// Для наглядности показываем символ и частоту
		std::cout << "'" << pair.first << "` " << pair.second;
		std::cout << std::endl;
	}


	return 0;
}