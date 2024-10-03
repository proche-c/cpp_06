/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	*data = new Data;
	data->name = "Gandalf";
	data->ability = "magic";
	data->lifePoints = 10;
	uintptr_t	intNumber;
	Data	*dataSerialized;
	intNumber = Serializer::serialize(data);
	dataSerialized = Serializer::deserialize(intNumber);
	std::cout << "Initial data: " << data << std::endl;
	std::cout << "intNumber after serialize: " << intNumber << std::endl;
	std::cout << "dataSerialized after deserialize: " << intNumber << std::endl;
	std::cout << "dataSerialized->name: " << dataSerialized->name << std::endl;
	std::cout << "dataSerialized->ability: " << dataSerialized->ability << std::endl;
	std::cout << "dataSerialized->lifePoints: " << dataSerialized->lifePoints << std::endl;

	return 0;
}