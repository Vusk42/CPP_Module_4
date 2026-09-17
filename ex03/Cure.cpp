/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:05:34 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/11 17:48:38 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure: " << this->_type
		<< ": Default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure: " << this->_type
		<< ": Copy constructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	std::cout << "Cure: " << this->_type
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
		this->AMateria::operator=(other);
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure: " << this->_type
		<< ": Destructor called" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"
		<< std::endl;
}
