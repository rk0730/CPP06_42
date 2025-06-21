#include "ScalarConverter.hpp"
#include <cctype>  // for isprint, isdigit
#include <cmath>   // for isinf, isnan (C99 features, but widely supported in C++98 compilers)
#include <cstdlib> // for std::strtod
#include <iomanip> // for std::fixed, std::setprecision
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void printChar(double d, bool impossible)
{
	std::cout << "char: ";
	if (impossible || std::isnan(d) || std::isinf(d) || d < 0 || d > 255)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(d);
		if (std::isprint(c))
		{
			std::cout << "'" << c << "'" << std::endl;
		}
		else
		{
			std::cout << "Non displayable" << std::endl;
		}
	}
}

void printInt(double d, bool impossible)
{
	std::cout << "int: ";
	if (impossible || std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() ||
		d > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(d) << std::endl;
	}
}

void printFloat(double d, bool impossible)
{
	std::cout << "float: ";
	if (impossible)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<float>(d) << "f" << std::endl;
	}
}

void printDouble(double d, bool impossible)
{
	std::cout << "double: ";
	if (impossible)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << d << std::endl;
	}
}

// --- メインの変換メソッド ---

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	std::string input = literal;
	// 'f'で終わる疑似リテラルを標準的な形式に変換してstrtodで扱えるようにする
	if (literal == "-inff")
		input = "-inf";
	else if (literal == "+inff")
		input = "+inf";
	else if (literal == "nanf")
		input = "nan";

	char *end = NULL;
	double d = std::strtod(input.c_str(), &end);

	bool impossible = false;
	// パース結果を検証
	// 1. 文字リテラルの場合: 'c' (argvで渡されるとc), aなど
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		d = static_cast<double>(input[0]);
	}
	// 2. 不正な入力の場合: "42a", "hello" など
	//    endが文字列の終端でもなく、'f'でもない場合はエラー
	else if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0'))
	{
		impossible = true;
	}

	// 全ての型に変換して表示
	// 小数点以下を.0で表示するよう整形
	std::cout << std::fixed << std::setprecision(1);

	printChar(d, impossible);
	printInt(d, impossible);
	printFloat(d, impossible);
	printDouble(d, impossible);
}
