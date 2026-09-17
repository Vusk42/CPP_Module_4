/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:03:22 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:42:05 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog(void);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

#endif
