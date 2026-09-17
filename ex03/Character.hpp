/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:05:40 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 18:01:51 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define INVENTORY_SIZE 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[INVENTORY_SIZE];

		AMateria**		_floor;
		unsigned int	_floorSize;
		unsigned int	_floorCapacity;

		void	_dropOnFloor(AMateria* m);
		void	_pickUpFromFloor(AMateria* m);
		void	_clearFloor(void);
		void	_clearInventory(void);
		void	_copyInventory(const Character& other);

	public:
		Character(void);
		Character(std::string const & name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character(void);

		std::string const &	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		AMateria*		getInventorySlot(int idx) const;
		unsigned int	getFloorSize(void) const;
};

#endif
