#ifndef BIRD_H
#define BIRD_H

class Bird
{
private:
	std::string color;
public:
	Bird(std::string setColor);

	void printColor();
};

#endif