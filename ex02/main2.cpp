/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:47:13 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 14:38:35 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "-- TEST 1 --" << std::endl;
		std::cout << "-- Sound: --" << std::endl;
		const Dog*	j = new Dog();
		const Cat*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();

		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << "-- TEST 2 --" << std::endl;
		std::cout << "-- Sound: --" << std::endl;
		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	j = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		std::cout << std::endl;
	}
	{
		std::cout << "-- TEST 3 --" << std::endl;
		std::cout << "-- Cat Constructor: --" << std::endl << std::endl;
		Cat	Animal_test;
		std::cout << std::endl;
		
		std::cout << "-- Cat Copy: --" << std::endl << std::endl;
		Cat	Animal_test2(Animal_test);
		std::cout << std::endl;
		
		std::cout << "-- Cat Assigment: --" << std::endl << std::endl;
		Cat	Animal_test3;
		std::cout << std::endl;
		
		Animal_test = Animal_test3;
		std::cout << std::endl;
		
		Animal_test.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << "-- TEST 4 --" << std::endl;
		std::cout << "-- Dog Constructor: --" << std::endl << std::endl;
		Dog	Animal_test;
		std::cout << std::endl;
		
		std::cout << "-- Dog Copy: --" << std::endl << std::endl;
		Dog	Animal_test2(Animal_test);
		std::cout << std::endl;
		
		std::cout << "-- Dog Assigment: --" << std::endl << std::endl;
		Dog	Animal_test3;
		std::cout << std::endl;
		
		Animal_test = Animal_test3;
		std::cout << std::endl;
		
		Animal_test.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << "-- TEST 5 --" << std::endl;
		std::cout << "-- WrongAnimal Constructor: --" << std::endl << std::endl;
		WrongAnimal	Animal_test;
		std::cout << std::endl;
		
		std::cout << "-- WrongAnimal Copy: --" << std::endl << std::endl;
		WrongAnimal	Animal_test2(Animal_test);
		std::cout << std::endl;
		
		std::cout << "-- WrongAnimal Assigment: --" << std::endl << std::endl;
		WrongAnimal	Animal_test3;
		std::cout << std::endl;
		
		Animal_test = Animal_test3;
		std::cout << std::endl;
		
		Animal_test.makeSound();
		std::cout << std::endl;

	}
	{
		std::cout << "-- TEST 6 --" << std::endl;
		std::cout << "-- WrongCat Constructor: --" << std::endl << std::endl;
		WrongCat	Animal_test;
		std::cout << std::endl;
		
		std::cout << "-- WrongCat Copy: --" << std::endl << std::endl;
		WrongCat	Animal_test2(Animal_test);
		std::cout << std::endl;
		
		std::cout << "-- WrongCat Assigment: --" << std::endl << std::endl;
		WrongCat	Animal_test3;
		std::cout << std::endl;
		
		Animal_test = Animal_test3;
		std::cout << std::endl;
		
		Animal_test.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << "-- TEST 7 --" << std::endl;
		AAnimal	*tab_animal[20];
		int		i;

		for (i = 0; i < 10; i++){
			tab_animal[i] = new Dog();
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (i = 10; i < 20; i++){
			tab_animal[i] = new Cat();
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (i = 0; i < 20; i++){
			delete tab_animal[i];
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- TEST 8 --" << std::endl;
		Dog	Animal_test;

		std::cout << std::endl << "(Before) Dog Idea[1]:" << std::endl;
		std::cout << Animal_test.getBrain()->getIdeas(1) << std::endl;
		Animal_test.getBrain()->setIdeas("Salut", 1);
		std::cout << std::endl << "(After) Dog Idea[1]:" << std::endl;
		std::cout << Animal_test.getBrain()->getIdeas(1) << std::endl << std::endl;

		Dog	Animal_test2(Animal_test);
		std::cout << std::endl << "Proof of Deep Copy:" << std::endl;
		std::cout << Animal_test2.getBrain()->getIdeas(1) << std::endl << std::endl;

		Dog	Animal_test3;
		std::cout << std::endl << "Before Assignment Copy" << std::endl;
		std::cout << Animal_test3.getBrain()->getIdeas(1) << std::endl;
		std::cout << std::endl << "Assignment Copy" << std::endl;
		Animal_test3 = Animal_test;
		std::cout << std::endl << "Proof of Deep Copy:" << std::endl;
		std::cout << Animal_test3.getBrain()->getIdeas(1) << std::endl << std::endl;
	}
	return 0;
}

