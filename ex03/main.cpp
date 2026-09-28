/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:27:04 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 14:41:38 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void	testBasic(void)
{
	Character		random("Random player");
	ICharacter*		player = new Character("Wizard");
	ICharacter*		vampire = new Character("Vampire");
	IMateriaSource*	src = new MateriaSource();
	AMateria*		tmp;

	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	player->equip(tmp);
	tmp = src->createMateria("cure");
	player->equip(tmp);

	std::cout << std::endl << "--- using slot 0 on a stack Character, "
		<< "slot 1 on a heap one ---" << std::endl;
	player->use(0, random);
	player->use(1, *vampire);

	std::cout << std::endl;
	delete player;
	delete vampire;
	delete src;
}

static void	testMateria(AMateria* materia)
{
	ICharacter*	target = new Character("target");

	std::cout << std::endl;
	std::cout << "type: " << materia->getType() << std::endl;
	materia->use(*target);

	std::cout << std::endl << "--- clone, then delete the original ---"
		<< std::endl;
	AMateria*	clone = materia->clone();
	delete materia;

	std::cout << "clone type: " << clone->getType() << std::endl;
	clone->use(*target);

	std::cout << std::endl;
	delete clone;
	delete target;
}

static void	testCharacter(void)
{
	ICharacter*	wizard = new Character("Wizard");
	ICharacter*	vampire = new Character("Vampire");
	AMateria*	ice = new Ice();
	AMateria*	secondIce = new Ice();
	AMateria*	cure = new Cure();
	AMateria*	secondCure = new Cure();
	AMateria*	thirdCure = new Cure();

	std::cout << std::endl;
	wizard->equip(ice);
	wizard->equip(secondIce);
	wizard->equip(cure);
	wizard->equip(secondCure);

	std::cout << std::endl << "--- a fifth Materia does not fit ---" << std::endl;
	wizard->equip(thirdCure);

	std::cout << std::endl << "--- unequip slot 0, then equip it again ---"
		<< std::endl;
	wizard->unequip(0);
	wizard->equip(ice);

	std::cout << std::endl << "--- using every slot twice ---" << std::endl;
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		wizard->use(idx, *vampire);
		wizard->use(idx, *vampire);
	}

	std::cout << std::endl;
	delete wizard;
	delete vampire;
	delete thirdCure;
}

static void	testMateriaSource(void)
{
	IMateriaSource*	src = new MateriaSource();
	AMateria*		tmp;

	std::cout << std::endl << "--- an empty source knows nothing ---"
		<< std::endl;
	tmp = src->createMateria("ice");
	delete tmp;
	tmp = src->createMateria("cure");
	delete tmp;
	tmp = src->createMateria("fire");

	std::cout << std::endl << "--- learning a null Materia does nothing ---"
		<< std::endl;
	src->learnMateria(tmp);

	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	delete src;
}

int	main(void)
{
	std::cout << "=== Basic test ===" << std::endl;
	testBasic();

	std::cout << std::endl << "=== Ice: use() and clone() ===" << std::endl;
	testMateria(new Ice());

	std::cout << std::endl << "=== Cure: use() and clone() ===" << std::endl;
	testMateria(new Cure());

	std::cout << std::endl << "=== Equip, unequip and use ===" << std::endl;
	testCharacter();

	std::cout << std::endl << "=== MateriaSource ===" << std::endl;
	testMateriaSource();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
