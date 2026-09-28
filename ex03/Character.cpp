/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:05:45 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/23 17:38:18 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) :
	_name("Darius"),
	_floor(0),
	_floorSize(0),
	_floorCapacity(0)
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		this->_inventory[idx] = 0;
	std::cout << "Character: " << this->_name
		<< ": Default constructor called" << std::endl;
}

Character::Character(std::string const & name) :
	_name(name),
	_floor(0),
	_floorSize(0),
	_floorCapacity(0)
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		this->_inventory[idx] = 0;
	std::cout << "Character: " << this->_name
		<< ": Name constructor called" << std::endl;
}

Character::Character(const Character& other) :
	ICharacter(other),
	_name(other._name),
	_floor(0),
	_floorSize(0),
	_floorCapacity(0)
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		this->_inventory[idx] = 0;
	this->_copyInventory(other);
	std::cout << "Character: " << this->_name
		<< ": Copy constructor called" << std::endl;
}

Character&	Character::operator=(const Character& other)
{
	std::cout << "Character: " << this->_name
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_clearInventory();
		this->_copyInventory(other);
	}
	return (*this);
}

Character::~Character(void)
{
	this->_clearInventory();
	this->_clearFloor();
	std::cout << "Character: " << this->_name
		<< ": Destructor called" << std::endl;
}

void	Character::_clearInventory(void)
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
}

void	Character::_copyInventory(const Character& other)
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		if (other._inventory[idx])
			this->_inventory[idx] = other._inventory[idx]->clone();
	}
}

void	Character::_dropOnFloor(AMateria* m)
{
	if (this->_floorSize == this->_floorCapacity)
	{
		unsigned int	newCapacity;
		AMateria**		newFloor;

		newCapacity = 4;
		if (this->_floorCapacity)
			newCapacity = this->_floorCapacity * 2;
		newFloor = new AMateria*[newCapacity];
		for (unsigned int idx = 0; idx < this->_floorSize; idx++)
			newFloor[idx] = this->_floor[idx];
		delete [] this->_floor;
		this->_floor = newFloor;
		this->_floorCapacity = newCapacity;
	}
	this->_floor[this->_floorSize] = m;
	this->_floorSize++;
}

void	Character::_pickUpFromFloor(AMateria* m)
{
	for (unsigned int idx = 0; idx < this->_floorSize; idx++)
	{
		if (this->_floor[idx] == m)
		{
			this->_floor[idx] = this->_floor[this->_floorSize - 1];
			this->_floorSize--;
			return ;
		}
	}
}

void	Character::_clearFloor(void)
{
	for (unsigned int idx = 0; idx < this->_floorSize; idx++)
		delete this->_floor[idx];
	delete [] this->_floor;
	this->_floor = 0;
	this->_floorSize = 0;
	this->_floorCapacity = 0;
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		if (this->_inventory[idx] == m)
			return ;
	}
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		if (!this->_inventory[idx])
		{
			this->_pickUpFromFloor(m);
			this->_inventory[idx] = m;
			std::cout << this->_name << " equips " << m->getType()
				<< " in slot " << idx << std::endl;
			return ;
		}
	}
	std::cout << this->_name << " has a full inventory: " << m->getType()
		<< " is left untouched" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !this->_inventory[idx])
		return ;
	std::cout << this->_name << " drops " << this->_inventory[idx]->getType()
		<< " from slot " << idx << " on the floor" << std::endl;
	this->_dropOnFloor(this->_inventory[idx]);
	this->_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

AMateria*	Character::getInventorySlot(int idx) const
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return (0);
	return (this->_inventory[idx]);
}

unsigned int	Character::getFloorSize(void) const
{
	return (this->_floorSize);
}
