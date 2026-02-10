#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){ *this = other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void	helper(std::string literal)
{
	std::string val;
	if (literal == "-inff" || literal == "-inf")
		val = "-inf";
	else if (literal == "+inff" || literal == "+inf")
		val = "+inf";
	else if (literal == "nanf" || literal == "nan")
		val = "nan";
	std::cout << "float: " << val << 'f' << std::endl;
	std::cout << "double: " << val << std::endl;
}

void charprint(const double &num){
	if (num < 0 || num > 127)
		std::cout << "char : impossible" << std::endl;
	else if (std::isprint(num))
        std::cout << "char: " << static_cast<char>(num) << std::endl;
	else
        std::cout << "char: " << "Non displayable" << std::endl;
}

void intprint(const double &num){
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

}

void floatprint(const double &num){
	if (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(num) << 'f' << std::endl;
}

void doubleprint(const double &num){
	if (num > std::numeric_limits<double>::max() || num < -std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	printconvert(const double &num)
{
	charprint(num);
	intprint(num);
	floatprint(num);
	doubleprint(num);
}

void ScalarConverter::convert(std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		helper(literal);
	}
	else if (literal.empty())
		throw std::runtime_error("error");
	else if (literal.length() == 1)
	{
		if (isdigit(literal[0]))
			printconvert(atoi(literal.c_str()));
		else
			printconvert(literal[0]);
	}
	else
	{
		char *end = NULL;

		if (literal[literal.length() - 1] == 'f')
			literal[literal.length() - 1] = '\0';

		double n = strtod(literal.c_str(), &end);

		if (*end != '\0')
			throw std::runtime_error("error");
		if (literal[literal.length() - 1] == '.' || literal[0] == '.')
			throw std::runtime_error("error");
		if ((literal[0] == '-' || literal[0] == '+') && literal[1] == '.')
			throw std::runtime_error("error");
		printconvert(n);
	}
}