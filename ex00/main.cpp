/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:12:56 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:41:04 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== Subject test: real polymorphism ===" << std::endl;
	{
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl << "--- deleting through Animal* ---"
			<< std::endl;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl
		<< "=== Wrong polymorphism: the base sound is used ===" << std::endl;
	{
		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	i = new WrongCat();

		std::cout << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		std::cout << std::endl << "--- same object, static WrongCat type ---"
			<< std::endl;
		const WrongCat	real;
		real.makeSound();

		std::cout << std::endl;
		delete meta;
		delete i;
	}

	std::cout << std::endl << "=== Objects on the stack ===" << std::endl;
	{
		Dog	rex;
		Cat	felix;

		std::cout << std::endl;
		std::cout << rex.getType() << ": ";
		rex.makeSound();
		std::cout << felix.getType() << ": ";
		felix.makeSound();
		std::cout << std::endl;
	}

	std::cout << std::endl << "=== Copy and assignment ===" << std::endl;
	{
		Dog	original;
		Dog	copy(original);
		Dog	assigned;

		assigned = original;
		std::cout << std::endl;
		std::cout << "copy type: " << copy.getType() << " -> ";
		copy.makeSound();
		std::cout << "assigned type: " << assigned.getType() << " -> ";
		assigned.makeSound();
		std::cout << std::endl;
	}

	std::cout << std::endl << "=== An array of Animal pointers ==="
		<< std::endl;
	{
		const Animal*	zoo[4];

		zoo[0] = new Dog();
		zoo[1] = new Cat();
		zoo[2] = new Dog();
		zoo[3] = new Cat();

		std::cout << std::endl;
		for (int idx = 0; idx < 4; idx++)
		{
			std::cout << zoo[idx]->getType() << " says: ";
			zoo[idx]->makeSound();
		}

		std::cout << std::endl;
		for (int idx = 0; idx < 4; idx++)
			delete zoo[idx];
	}

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
