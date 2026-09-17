/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:05:12 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:54:52 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("unknown")
{
	std::cout << "AMateria: " << this->_type
		<< ": Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria: " << this->_type
		<< ": Type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	std::cout << "AMateria: " << this->_type
		<< ": Copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria: " << this->_type
		<< ": Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria: " << this->_type
		<< ": Destructor called" << std::endl;
}

std::string const &	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* does nothing to " << target.getName() << " *" << std::endl;
}
