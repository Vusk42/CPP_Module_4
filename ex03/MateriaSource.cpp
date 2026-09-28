/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:06:01 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/23 17:40:09 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int idx = 0; idx < TEMPLATES_SIZE; idx++)
		this->_templates[idx] = 0;
	std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int idx = 0; idx < TEMPLATES_SIZE; idx++)
		this->_templates[idx] = 0;
	this->_copyTemplates(other);
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_clearTemplates();
		this->_copyTemplates(other);
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	this->_clearTemplates();
	std::cout << "MateriaSource: Destructor called" << std::endl;
}

void	MateriaSource::_clearTemplates(void)
{
	for (int idx = 0; idx < TEMPLATES_SIZE; idx++)
	{
		delete this->_templates[idx];
		this->_templates[idx] = 0;
	}
}

void	MateriaSource::_copyTemplates(const MateriaSource& other)
{
	for (int idx = 0; idx < TEMPLATES_SIZE; idx++)
	{
		if (other._templates[idx])
			this->_templates[idx] = other._templates[idx]->clone();
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int idx = 0; idx < TEMPLATES_SIZE; idx++)
	{
		if (!this->_templates[idx])
		{
			this->_templates[idx] = m;
			std::cout << "MateriaSource learns " << m->getType()
				<< " in slot " << idx << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource already knows 4 Materias: " << m->getType()
		<< " is forgotten" << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int idx = 0; idx < TEMPLATES_SIZE; idx++)
	{
		if (this->_templates[idx] && this->_templates[idx]->getType() == type)
			return (this->_templates[idx]->clone());
	}
	std::cout << "MateriaSource does not know any \"" << type << "\" Materia"
		<< std::endl;
	return (0);
}
