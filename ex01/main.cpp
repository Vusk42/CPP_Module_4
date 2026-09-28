/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:03:44 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:42:30 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define ZOO_SIZE 8

static void	testSubjectMain(void)
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl << "--- deleting through Animal* ---" << std::endl;
	delete j;
	delete i;
}

static void	testZoo(void)
{
	Animal*	zoo[ZOO_SIZE];

	for (int idx = 0; idx < ZOO_SIZE / 2; idx++)
		zoo[idx] = new Dog();
	for (int idx = ZOO_SIZE / 2; idx < ZOO_SIZE; idx++)
		zoo[idx] = new Cat();

	std::cout << std::endl;
	for (int idx = 0; idx < ZOO_SIZE; idx++)
	{
		std::cout << "zoo[" << idx << "] (" << zoo[idx]->getType() << "): ";
		zoo[idx]->makeSound();
	}

	std::cout << std::endl << "--- deleting every animal as an Animal ---"
		<< std::endl;
	for (int idx = 0; idx < ZOO_SIZE; idx++)
		delete zoo[idx];
}

static void	testDeepCopyConstructor(void)
{
	Dog	original;

	original.getBrain()->ideas[0] = "I want a bone";
	original.getBrain()->ideas[1] = "Is that a squirrel?";

	std::cout << std::endl;
	Dog	copy(original);

	std::cout << std::endl;
	std::cout << "original brain address: " << original.getBrain() << std::endl;
	std::cout << "copy brain address    : " << copy.getBrain() << std::endl;
	std::cout << "copy ideas[0]         : " << copy.getBrain()->ideas[0]
		<< std::endl;

	copy.getBrain()->ideas[0] = "I want a ball";
	std::cout << "after editing the copy, original ideas[0]: "
		<< original.getBrain()->ideas[0] << std::endl;
	std::cout << std::endl;
}

static void	testDeepCopyAssignment(void)
{
	Cat	original;
	Cat	assigned;

	original.getBrain()->ideas[0] = "The box is mine";

	std::cout << std::endl;
	assigned = original;

	std::cout << std::endl;
	std::cout << "original brain address: " << original.getBrain() << std::endl;
	std::cout << "assigned brain address: " << assigned.getBrain() << std::endl;
	std::cout << "assigned ideas[0]     : " << assigned.getBrain()->ideas[0]
		<< std::endl;

	assigned.getBrain()->ideas[0] = "The bag is mine";
	std::cout << "after editing the assigned one, original ideas[0]: "
		<< original.getBrain()->ideas[0] << std::endl;
	std::cout << std::endl;
}

static void	testWrongAnimal(void)
{
	const WrongAnimal*	i = new WrongCat();

	std::cout << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound();

	std::cout << std::endl;
	delete i;
}

int	main(void)
{
	std::cout << "=== Subject test ===" << std::endl;
	testSubjectMain();

	std::cout << std::endl << "=== An array of half Dogs, half Cats ==="
		<< std::endl;
	testZoo();

	std::cout << std::endl << "=== Deep copy: copy constructor ===" << std::endl;
	testDeepCopyConstructor();

	std::cout << std::endl << "=== Deep copy: copy assignment ===" << std::endl;
	testDeepCopyAssignment();

	std::cout << std::endl << "=== WrongAnimal is still wrong ===" << std::endl;
	testWrongAnimal();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
