#include <iostream>
#include <Windows.h>

//#define MAIN_RETURN 0

struct point {
	double m_x;
	double m_y;
	point(double x, double y) 
	{
		m_x = x;
		m_y = y;
	}
};

void print_point(const point& point_object) 
{
	std::cout << "x:" << point_object.m_x << ", y: " << point_object.m_y << std::endl;
}


int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	

	for (int i = 0; i < 5; i++)
	{
		point my_point(i, i*2);
		print_point(my_point);
	}

	return 0;
}