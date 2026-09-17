/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:05:56 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:54:41 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define TEMPLATES_SIZE 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_templates[TEMPLATES_SIZE];

		void	_clearTemplates(void);
		void	_copyTemplates(const MateriaSource& other);

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource(void);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif
