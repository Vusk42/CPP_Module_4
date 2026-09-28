/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:03:27 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/23 17:33:17 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) :
	AAnimal("Dog"),
	_brain(new Brain())
{
	std::cout << "Dog: " << this->type
		<< ": Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) :
	AAnimal(other),
	_brain(new Brain(*other._brain))
{
	std::cout << "Dog: " << this->type
		<< ": Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: " << this->type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->AAnimal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog: " << this->type
		<< ": Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}
