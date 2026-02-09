// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Person.h"

#include "Animals/Bird.h"


int main()
{
	std::cout << "Hello CMake." << std::endl;

	std::cout << std::endl;

	Person person_1(25);
	person_1.printAge();

	Bird bird_1("green");
	bird_1.printColor();

	return EXIT_SUCCESS;
}
