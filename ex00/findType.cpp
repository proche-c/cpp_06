/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isDouble(std::string &str, size_t separator)
{
	size_t	i;

	i = 0;
	while (i < separator)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	i = separator + 1;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	long double	l = strtold(str.c_str(), NULL);
	if (l < MIN_DOUBLE || l > MAX_DOUBLE)
		return (0);
	return (1);
}

static bool	isFloat(std::string &str, size_t separator, size_t f)
{
	size_t	i;

	if (f != str.length() - 1)
		return 0;
	i = 0;
	while (i < separator)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;		
	}
	i = separator + 1;
	while (i < f)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;		
	}
	long double	l = strtold(str.c_str(), NULL);
	if (l < MIN_FLOAT || l > MAX_FLOAT)
		return (0);
	return (1);	
}

static bool	isInt(std::string &str)
{
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str.length() > 11)
			return (0);
		i++;
	}
	else
	{
		if (str.length() > 10)
			return (0);
	}
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	long long l = atol(str.c_str());
	if (l < MIN_INT || l > MAX_INT)
		return (0);
	return (1);
}

static bool	isPseudo(std::string &str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf")
		|| !str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
			return (1);
	return (0);
}

static bool	isChar(std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (1);
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (1);
	return (0);
}

inputType	findType(std::string &str)
{
	size_t	separator = str.find(".");
	size_t	f = str.find("f");

	if (isPseudo(str))
		return PSEUDO;
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (separator != std::string::npos && f != std::string::npos && isFloat(str, separator, f))
		return FLOAT;
	if (separator != std::string::npos && f == std::string::npos && isDouble(str, separator))
		return DOUBLE;
	return INVALID;
}

