/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
#include <string> 
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#define MIN_INT std::numeric_limits<int>::min()
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()
#define MAX_DOUBLE std::numeric_limits<double>::max()

enum	inputType
{
	PSEUDO = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter & operator=(ScalarConverter const &src);

	public:
		static void	convert(std::string &str);

};

inputType	findType(std::string &str);
void		printPseudo(std::string &str);
void		printChar(std::string &str);
void		printInt(std::string &str);
void		printFloat(std::string &str);
void		printDouble(std::string &str);

#endif