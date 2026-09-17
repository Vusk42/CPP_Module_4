/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:02:51 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:41:11 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual ~Animal(void);

		virtual void		makeSound(void) const;
		const std::string&	getType(void) const;
};

#endif
