#include <iostream>
#include <Windows.h>

// RAII - Resource Acquisition Is Initialization (Получение ресурса есть инициализация) -
//	программная идиома, смысл которой заключается в том, 
//		что с помощью тех или иных программных механизмов получение 
//			некоторого ресурса неразрывно совмещается с инициализацией, а освобождение — с уничтожением объекта.

// Как надо
class Int {
public:
	// Конструктор
	Int(int aValue = 10) : value(aValue) {
		std::cout << "Int(int value)" << std::endl;
	}
	// Деструктор
	~Int() { std::cout << "~Int()" << std::endl; }

	int value;
};

class IntArray {
public:
	// Конструктор
	IntArray(int aSize) {
		data = new Int[aSize];
	}
	//Деструктор
	~IntArray() { delete[] data; }

private:
	Int* data = nullptr;
};
//

class smart_array {
public:
	smart_array(int size_arr) {
		size = size_arr;
		arr = new int[size_arr]();
	}

	void add_element(int num) {
		/*if (num >= size) {
			std::cout << "Array is full. Cannot add more elements." << std::endl;
		}*/
		arr[index] = num;
		index++;
	}

	int get_element(int num) {
		//std::cout << "size = " << size << std::endl;
		if (num >= size) {
		//	throw "Index out of bounds.";
			std::cout << "Error: Incorrect index" << std::endl;
		} 
		else {
			// std::cout << "Пук" << std::endl; 
			return arr[num];
		}
	}

	~smart_array() {
		delete[] arr;
		std::cout << "~smart_array" << std::endl;
	}
private:
	int* arr = nullptr;
	int index = 0;
	int size = 0;
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Как надо. Как только вышли за рамки блока кода {} - вызывается деструктор, который удаляет использованную динамическую память. 
	// Вручную этого делать не приходится.
	try
	{
		IntArray intArray(10);
	}
	catch (...)
	{}
	//

	std::cout << std::endl << std::endl << std::endl;

	// Как НЕ надо
	Int* arr = nullptr;
	try
	{
		arr = new Int[10];
		delete[] arr;
	}
	catch (...)
	{
		if (arr != nullptr)
		{
			delete[] arr;
		}
	}
	//

	std::cout << std::endl << std::endl << std::endl;

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		//arr.add_element(14);
		//arr.add_element(15);

		std::cout << arr.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.get_element(2) << std::endl;
		std::cout << arr.get_element(3) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
	}
	catch (...) {

	}

	return 0;
}