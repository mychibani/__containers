#include <iostream>
#include <vector>
#include "Vector.hpp"

int	main(void)
{
	ft::vector<int> test;
	std::vector<int> test2;

	ft::vector<int> tmp(5);

	std::cout << "size ft::vector = " << test.size() << std::endl;
	std::cout << "size std::vector = " << test2.size() << std::endl;

}
