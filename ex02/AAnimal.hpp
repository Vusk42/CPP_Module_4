/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:47:02 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:43:11 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	type;

		AAnimal(void);
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& other);

	public:
		virtual ~AAnimal(void);

		virtual void		makeSound(void) const = 0;
		const std::string&	getType(void) const;
};

#endif
