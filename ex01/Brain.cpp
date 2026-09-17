/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:03:16 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:41:14 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	for (int idx = 0; idx < 100; idx++)
		this->ideas[idx] = "...";
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int idx = 0; idx < 100; idx++)
		this->ideas[idx] = other.ideas[idx];
	std::cout << "Brain: Copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int idx = 0; idx < 100; idx++)
			this->ideas[idx] = other.ideas[idx];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain: Destructor called" << std::endl;
}
