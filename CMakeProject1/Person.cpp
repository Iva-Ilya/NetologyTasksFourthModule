#include <iostream>
#include "Person.h"

Person::Person(int setAge) : age(setAge)
{
}

void Person::printAge() { std::cout << "Age: " << age << std::endl; }