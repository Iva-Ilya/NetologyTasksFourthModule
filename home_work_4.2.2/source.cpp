#include <iostream>
#include <Windows.h>

// RAII - Resource Acquisition Is Initialization (Получение ресурса есть инициализация) -
//	программная идиома, смысл которой заключается в том, 
//		что с помощью тех или иных программных механизмов получение 
//	


class smart_array {
public:
	smart_array(int size_arr) {
		size = size_arr;
		arr = new int[size_arr]();
	}

	void add_element(int num) {
		if (index == size) {
			throw "Array is full. Cannot add more elements.";
		}
		arr[index] = num;
		index++;

	}

	int get_element(int num) {
		if (num >= size) {
			throw "Index out of bounds.";
		}
		else {
			// std::cout << "444" << std::endl; 
			return arr[num];
		}
	}

	smart_array operator=(const smart_array& other_arr) {
		delete[] arr;
		size = other_arr.size;
		arr = new int[size];

		for (int i = 0; i < size; ++i) {
			arr[i] = other_arr.arr[i];
		}

		return *arr;
	}

	void print() {
		std::cout << "[";
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i];
			if (i < size - 1) std::cout << ", ";
		}
		std::cout << "]" << std::endl;
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

	try {
		smart_array arr1(5);
		arr1.add_element(1);
		arr1.add_element(4);
		arr1.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr1.print();
		new_array.print();

		arr1 = new_array;

		arr1.print();
		new_array.print();
	}
	catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}