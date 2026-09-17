/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:06:07 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/11 18:13:42 by marudlof         ###   ########.fr       */
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

static void	testSubjectMain(void)
{
	IMateriaSource*	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	std::cout << std::endl << "--- the expected output ---" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "---------------------------" << std::endl << std::endl;

	delete bob;
	delete me;
	delete src;
}

static void	testUnknownMateria(void)
{
	MateriaSource	src;

	src.learnMateria(new Ice());

	std::cout << std::endl;
	AMateria*	unknown = src.createMateria("fire");

	std::cout << "createMateria(\"fire\") returned "
		<< (unknown ? "a Materia" : "0") << std::endl << std::endl;
}

static void	testSourceOverflow(void)
{
	MateriaSource	src;

	for (int idx = 0; idx < 4; idx++)
		src.learnMateria(new Ice());

	std::cout << std::endl << "--- a fifth Materia is one too many ---"
		<< std::endl;
	src.learnMateria(new Cure());

	std::cout << std::endl;
	AMateria*	cure = src.createMateria("cure");
	std::cout << "createMateria(\"cure\") returned "
		<< (cure ? "a Materia" : "0") << std::endl << std::endl;
}

static void	testFullInventory(void)
{
	Character		me("me");
	Character		target("target");
	AMateria*		extra;

	for (int idx = 0; idx < 4; idx++)
		me.equip(new Ice());

	std::cout << std::endl << "--- a fifth Materia does not fit ---"
		<< std::endl;
	extra = new Cure();
	me.equip(extra);
	std::cout << "slot 3 still holds " << me.getInventorySlot(3)->getType()
		<< ", the Cure stays ours to free" << std::endl;
	delete extra;

	std::cout << std::endl << "--- out of range and empty slots do nothing ---"
		<< std::endl;
	me.use(-1, target);
	me.use(4, target);
	me.use(42, target);
	me.unequip(-1);
	me.unequip(9);
	std::cout << "nothing happened, and nothing crashed" << std::endl
		<< std::endl;
}

static void	testUnequip(void)
{
	Character		me("me");
	Character		target("target");
	AMateria*		ice = new Ice();

	me.equip(ice);
	std::cout << std::endl;
	me.unequip(0);

	std::cout << "the Materia is still alive at " << ice
		<< ": " << ice->getType() << std::endl;
	std::cout << "floor size: " << me.getFloorSize() << std::endl;
	std::cout << "using the empty slot 0: ";
	me.use(0, target);
	std::cout << "(nothing)" << std::endl;

	std::cout << std::endl << "--- picking it up again ---" << std::endl;
	me.equip(ice);
	std::cout << "floor size: " << me.getFloorSize() << std::endl;
	me.use(0, target);
	std::cout << std::endl;
}

static void	printState(Character const & character)
{
	std::cout << character.getName() << ":";
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		AMateria*	slot = character.getInventorySlot(idx);

		std::cout << " [" << idx << ": "
			<< (slot ? slot->getType() : "empty") << "]";
	}
	std::cout << " | floor size: " << character.getFloorSize() << std::endl;
}

static void	testDropOnFloor(void)
{
	MateriaSource	src;
	Character		me("me");
	const int		unequipOrder[INVENTORY_SIZE] = {2, 0, 3, 1};

	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	for (int round = 0; round < 3; round++)
	{
		std::cout << std::endl << "--- round " << round
			<< ": equip 4 Materias, then drop them all ---" << std::endl;
		for (int idx = 0; idx < INVENTORY_SIZE; idx++)
			me.equip(src.createMateria(idx % 2 ? "cure" : "ice"));
		printState(me);
		for (int idx = 0; idx < INVENTORY_SIZE; idx++)
			me.unequip(unequipOrder[idx]);
		printState(me);
	}

	std::cout << std::endl << "--- 12 Materias on the floor: it grew 0 -> 4 -> 8"
		<< " -> 16 ---" << std::endl;
	std::cout << "floor size: " << me.getFloorSize()
		<< (me.getFloorSize() == 12 ? " (OK)" : " (KO)") << std::endl;

	std::cout << std::endl << "--- unequipping an empty slot drops nothing ---"
		<< std::endl;
	me.unequip(0);
	printState(me);

	std::cout << std::endl << "--- the destructors free the floor ---"
		<< std::endl;
}

static void	testPickUpFromFloor(void)
{
	Character	me("me");
	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();
	AMateria*	secondIce = new Ice();
	AMateria*	secondCure = new Cure();

	std::cout << std::endl;
	me.equip(ice);
	me.equip(cure);
	me.equip(secondIce);
	me.equip(secondCure);
	printState(me);

	std::cout << std::endl << "--- drop everything: floor = "
		<< "{ice, cure, secondIce, secondCure} ---" << std::endl;
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		me.unequip(idx);
	printState(me);

	std::cout << std::endl << "--- pick up from the middle (cure) ---"
		<< std::endl;
	me.equip(cure);
	printState(me);
	std::cout << "slot 0 is the same cure: "
		<< (me.getInventorySlot(0) == cure ? "yes" : "NO") << std::endl;

	std::cout << std::endl << "--- pick up the last one (secondIce) ---"
		<< std::endl;
	me.equip(secondIce);
	printState(me);
	std::cout << "slot 1 is the same secondIce: "
		<< (me.getInventorySlot(1) == secondIce ? "yes" : "NO") << std::endl;

	std::cout << std::endl << "--- pick up the first one (ice) ---" << std::endl;
	me.equip(ice);
	printState(me);
	std::cout << "slot 2 is the same ice: "
		<< (me.getInventorySlot(2) == ice ? "yes" : "NO") << std::endl;

	std::cout << std::endl << "--- secondCure was moved twice, it is still found ---"
		<< std::endl;
	me.equip(secondCure);
	printState(me);
	std::cout << "slot 3 is the same secondCure: "
		<< (me.getInventorySlot(3) == secondCure ? "yes" : "NO") << std::endl;

	std::cout << std::endl << "--- a full inventory leaves the Materia on the "
		<< "floor ---" << std::endl;
	me.unequip(3);
	printState(me);
	AMateria*	freshCure = new Cure();
	me.equip(freshCure);
	std::cout << "a Materia that was never on the floor: floor size is still "
		<< me.getFloorSize() << std::endl;
	me.equip(secondCure);
	printState(me);
	std::cout << "secondCure is still on the floor, still ours to free"
		<< std::endl;

	std::cout << std::endl << "--- equipping an already equipped Materia does "
		<< "nothing ---" << std::endl;
	me.unequip(0);
	printState(me);
	me.equip(ice);
	printState(me);
	std::cout << "slot 0 is still empty: "
		<< (me.getInventorySlot(0) ? "NO" : "yes") << std::endl;

	std::cout << std::endl << "--- the destructor frees 3 equipped + 2 on the "
		<< "floor ---" << std::endl;
}

static void	testDeepCopy(void)
{
	Character	original("original");
	Character	target("target");

	original.equip(new Ice());
	original.equip(new Cure());

	std::cout << std::endl << "--- copy constructor ---" << std::endl;
	Character	copy(original);

	std::cout << std::endl;
	std::cout << "original slot 0: " << original.getInventorySlot(0)
		<< " (" << original.getInventorySlot(0)->getType() << ")" << std::endl;
	std::cout << "copy slot 0    : " << copy.getInventorySlot(0)
		<< " (" << copy.getInventorySlot(0)->getType() << ")" << std::endl;
	std::cout << "different Materias: "
		<< (original.getInventorySlot(0) != copy.getInventorySlot(0)
			? "yes" : "NO (shallow!)") << std::endl;
	copy.use(0, target);

	std::cout << std::endl << "--- copy assignment ---" << std::endl;
	Character	assigned("assigned");

	assigned.equip(new Cure());
	std::cout << std::endl;
	assigned = original;

	std::cout << std::endl;
	std::cout << "assigned is now named " << assigned.getName() << std::endl;
	std::cout << "assigned slot 0: " << assigned.getInventorySlot(0)
		<< " (" << assigned.getInventorySlot(0)->getType() << ")" << std::endl;
	std::cout << "different Materias: "
		<< (original.getInventorySlot(0) != assigned.getInventorySlot(0)
			? "yes" : "NO (shallow!)") << std::endl;
	assigned.use(0, target);
	std::cout << std::endl;
}

static void	testMateriaAssignment(void)
{
	Ice		first;
	Ice		second;
	Cure	cure;

	std::cout << std::endl;
	first = second;
	std::cout << "an Ice assigned from an Ice is still: " << first.getType()
		<< std::endl;

	AMateria*	asBase = &first;
	*asBase = cure;
	std::cout << "an Ice assigned from a Cure is still: " << first.getType()
		<< std::endl << std::endl;
}

int	main(void)
{
	std::cout << "=== Subject test ===" << std::endl;
	testSubjectMain();

	std::cout << std::endl << "=== An unknown Materia type ===" << std::endl;
	testUnknownMateria();

	std::cout << std::endl << "=== A MateriaSource only knows 4 Materias ==="
		<< std::endl;
	testSourceOverflow();

	std::cout << std::endl << "=== A full inventory, and invalid slots ==="
		<< std::endl;
	testFullInventory();

	std::cout << std::endl << "=== unequip() does not delete the Materia ==="
		<< std::endl;
	testUnequip();

	std::cout << std::endl << "=== _dropOnFloor() grows the floor ==="
		<< std::endl;
	testDropOnFloor();

	std::cout << std::endl << "=== _pickUpFromFloor() takes the right Materia ==="
		<< std::endl;
	testPickUpFromFloor();

	std::cout << std::endl << "=== A Character copy is deep ===" << std::endl;
	testDeepCopy();

	std::cout << std::endl << "=== Assigning a Materia keeps its type ==="
		<< std::endl;
	testMateriaAssignment();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
