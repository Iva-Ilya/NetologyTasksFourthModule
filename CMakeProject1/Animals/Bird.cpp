#include <iostream>
#include "Bird.h"

Bird::Bird(std::string setColor) : color(setColor)
{
}

void Bird::printColor() { std::cout << "Color: " << color << std::endl; }