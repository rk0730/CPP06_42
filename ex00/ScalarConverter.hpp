#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
	static void convert(std::string const &literal);

private:
	ScalarConverter(); // Prevent instantiation
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();
};

#endif
