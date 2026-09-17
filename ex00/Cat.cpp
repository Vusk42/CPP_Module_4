/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:12:29 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:40:36 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat: " << this->type
		<< ": Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat: " << this->type
		<< ": Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: " << this->type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
		this->Animal::operator=(other);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat: " << this->type
		<< ": Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow... meow!" << std::endl;
}
