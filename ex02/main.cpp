/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:47:13 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:43:56 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define ZOO_SIZE 8

static void	testAbstract(void)
{
	std::cout << "AAnimal is abstract: the two lines below do not compile."
		<< std::endl;
	std::cout << "  AAnimal  meta;" << std::endl;
	std::cout << "  const AAnimal* meta = new AAnimal();" << std::endl;
	std::cout << "Only Dog and Cat can be built, through an AAnimal*."
		<< std::endl;

	// AAnimal			meta;
	// const AAnimal*	meta = new AAnimal();
}

static void	testZoo(void)
{
	AAnimal*	zoo[ZOO_SIZE];

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

	std::cout << std::endl << "--- deleting every animal as an AAnimal ---"
		<< std::endl;
	for (int idx = 0; idx < ZOO_SIZE; idx++)
		delete zoo[idx];
}

static void	testDeepCopyConstructor(void)
{
	Dog	original;

	original.getBrain()->ideas[0] = "I want a bone";

	std::cout << std::endl;
	Dog	copy(original);

	std::cout << std::endl;
	std::cout << "original brain address: " << original.getBrain() << std::endl;
	std::cout << "copy brain address    : " << copy.getBrain() << std::endl;
	std::cout << "different brains      : "
		<< (original.getBrain() != copy.getBrain() ? "yes" : "NO (shallow!)")
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
	std::cout << "different brains      : "
		<< (original.getBrain() != assigned.getBrain() ? "yes" : "NO (shallow!)")
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
	std::cout << "=== An abstract base class ===" << std::endl;
	testAbstract();

	std::cout << std::endl << "=== An array of half Dogs, half Cats ==="
		<< std::endl;
	testZoo();

	std::cout << std::endl << "=== Deep copy: copy constructor ===" << std::endl;
	testDeepCopyConstructor();

	std::cout << std::endl << "=== Deep copy: copy assignment ===" << std::endl;
	testDeepCopyAssignment();

	std::cout << std::endl << "=== WrongAnimal is still concrete and wrong ==="
		<< std::endl;
	testWrongAnimal();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
