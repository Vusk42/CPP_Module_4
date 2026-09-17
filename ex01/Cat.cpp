/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:03:38 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:41:56 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat: " << this->type
		<< ": Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat: " << this->type
		<< ": Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: " << this->type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat: " << this->type
		<< ": Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow... meow!" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}
