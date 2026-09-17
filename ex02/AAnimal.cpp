/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:47:07 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:43:08 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal: " << this->type
		<< ": Default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type)
{
	std::cout << "AAnimal: " << this->type
		<< ": String constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal: " << this->type
		<< ": Copy constructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal: " << this->type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal: " << this->type
		<< ": Destructor called" << std::endl;
}

const std::string&	AAnimal::getType(void) const
{
	return (this->type);
}
