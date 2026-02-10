#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "./program arg 1" << std::endl;
		return 1;
	}
	try{
		ScalarConverter::convert(av[1]);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}