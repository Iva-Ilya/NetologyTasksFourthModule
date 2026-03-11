#include <iostream>
#include <windows.h>
#include <vector>
#include <utility>

template <class T>
class table {
private:
	T** _table = nullptr;
	int rows = 0;
	int columns = 0;

public:
	table(int rows, int columns) {
		this->rows = rows;
		this->columns = columns;
		
		_table = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			_table[i] = new T[columns] {};
		}
	}

	// неконстантный оператор []
	T* operator[](int row) {
		/*if (row >= rows) {
			throw std::out_of_range("row index out of range");
		}*/
		return _table[row];
	}

	// константный оператор []
	const T* operator[](int row) const {
		/*if (row >= rows) {
			throw std::out_of_range("row index out of range");
		}*/
		return _table[row];
	}

	std::pair<int, int> Size() const {
		return { rows, columns };
	}

	~table() {
		for (int i = 0; i < rows; i++)
		{
			delete[] _table[i];
		}
		delete[] _table;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	table<int> Table(3,4);

	// заполняем значениями
	int counter = 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			Table[i][j] = counter++;
		}
	}

	// чтение и запись
	std::cout << "table[1][2] = " << Table[1][2] << std::endl;
	Table[1][2] = 100;
	std::cout << "after change: table[1][2] = " << Table[1][2] << std::endl;

	

	// вывод всей таблицы
	std::cout << "\nfull table:" << std::endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << Table[i][j] << "\t";
		}
		std::cout << std::endl;	
	}

	std::cout << std::endl;

	auto size = Table.Size();
	std::cout << "Table size: " << size.first << "x" << size.second << std::endl;

	// Работа с константной таблицей
	const table<int>& const_table = Table;
	std::cout << "\nConst access: " << const_table[1][2] << std::endl;
	// const_table[0][0] = 10;  // Ошибка - константный оператор


	return 0;
}


