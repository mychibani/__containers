#include <iostream>
#include <vector>

int	main(void)
{
	std::cout << "Hello World !" << std::endl;

	std::vector<int> tableau(4, 10);
	for (size_t i = 0; i < tableau.size(); ++i)
		std::cout << tableau[i] << std::endl;
	
	for (std::vector<int>::size_type i = 0; i < tableau.size(); ++i)
		std::cout << tableau[i] << std::endl;
}
