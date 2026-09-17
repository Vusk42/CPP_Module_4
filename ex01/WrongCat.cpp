/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:12:50 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:42:25 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat: " << this->type
		<< ": Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat: " << this->type
		<< ": Copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat: " << this->type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
		this->WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: " << this->type
		<< ": Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow... meow! (but you will never hear it)" << std::endl;
}
