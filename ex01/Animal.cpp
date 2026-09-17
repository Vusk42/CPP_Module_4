/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:02:56 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:41:08 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal: " << this->type
		<< ": Default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal: " << this->type
		<< ": String constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal: " << this->type
		<< ": Copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal: " << this->type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal: " << this->type
		<< ": Destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "* an animal makes an indistinct noise *" << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}
