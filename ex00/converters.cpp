/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printPseudo(std::string &str)
{
	if (!str.compare("-inff") || !str.compare("-inf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (!str.compare("+inff") || !str.compare("+inf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (!str.compare("nanf") || !str.compare("nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	return ;
}

void	printChar(std::string &str)
{
	char	c;

	c = str[0];
	if (str.length() == 3)
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c)  << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(4) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(4) << static_cast<double>(c) << std::endl;
}

void	printInt(std::string &str)
{
	int	i;

	i = atoi(str.c_str());
	if (i < 0 || i > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << std::setprecision(4) << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << std::setprecision(4) << static_cast<double>(i) << ".0" << std::endl;
}

void	printFloat(std::string &str)
{
	float	f;

	f = atof(str.c_str());
	if (f < 0 || f > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(f))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (f > MAX_INT || f < MIN_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (std::fabs(f - static_cast<int>(f)) < 0.00000000000000000000001)
		std::cout << "float: " << std::setprecision(4) << static_cast<float>(f) << ".0f" << std::endl;
	else
		std::cout << "float: " << std::setprecision(4) << static_cast<float>(f) << "f" << std::endl;
	if (std::fabs(f - static_cast<int>(f)) < 0.00000000000000000000001)
		std::cout << "double: " << std::setprecision(4) << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double: " << std::setprecision(4) << static_cast<double>(f) << std::endl;
}

void	printDouble(std::string &str)
{
	double	d;

	d = strtod(str.c_str(), NULL);
	if (d < 0 || d > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(d))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (d > MAX_INT || d < MIN_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > MAX_FLOAT || d < MIN_FLOAT)
		std::cout << "float: impossible" << std::endl;
	else
	{
		if (std::fabs(d - static_cast<int>(d)) < 0.00000000000000000000001)
			std::cout << "float: " << std::setprecision(4) << static_cast<float>(d) << ".0f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(4) << static_cast<float>(d) << "f" << std::endl;
	}
	if (std::fabs(d - static_cast<int>(d)) < 0.00000000000000000000001)
		std::cout << "double: " << std::setprecision(4) << static_cast<double>(d) << ".0" << std::endl;
	else
		std::cout << "double: " << std::setprecision(4) << static_cast<double>(d) << std::endl;
}