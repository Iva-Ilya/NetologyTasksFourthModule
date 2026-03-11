#include <iostream>
#include <windows.h>
#include <vector>

class Counter {
private:
	int sum;
	int count;
public:
	Counter() {
		sum = 0;
		count = 0;
	}

	void operator () (int number) {
		if (number % 3 == 0) {
			sum += number;
			count++;
		}
	}

	int get_sum() const {
		return sum;
	}

	int get_count() const {
		return count;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 }; // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12

	Counter c;

	// Применим функтор к каждому элементу вектора
	for (int num : numbers) {
		c(num);
	}

	std::cout << "[IN]: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "[OUT]: get_count() =  " << c.get_count() << std::endl;
	std::cout << "[OUT]: get_sum() = " << c.get_sum() << std::endl;


	return 0;
}