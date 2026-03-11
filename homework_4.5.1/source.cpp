#include <iostream>
#include <Windows.h>
#include <vector>

template <class T>
void squaring(T& a) {
	a = a * a;
}

template <class T>
void squaring(std::vector<T> &a) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = a[i] * a[i];
	}
	
}

template<class T>
void print_input(const T& value) {
	std::cout << "[IN]: " << value << std::endl;
}
template<class T>
void print_output(const T& value) {
	std::cout << "[OUT]: " << value << std::endl;
}

template<class T>
void print_input(const std::vector<T> &a) {
	std::cout << "[IN]: ";
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i];
		if (i < a.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}
template<class T>
void print_output(const std::vector<T>& a) {
	std::cout << "[OUT]: ";
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i];
		if (i < a.size() - 1) std::cout << ", ";
	}
	std::cout << std::endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num1 = 4;
	print_input(num1);
	squaring(num1);
	print_output(num1);
	
	std::cout << std::endl;

	std::vector<int> vec = { 2, 4, 6 };
	print_input(vec);
	squaring(vec);
	print_output(vec);

	std::cout << std::endl;

	std::vector<float> vec1 = { -3.0, -5.0, -7.0 };
	print_input(vec1);
	squaring(vec1);
	print_output(vec1);

	return 0;
}