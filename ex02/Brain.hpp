/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:03:11 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/10 17:43:18 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		std::string	ideas[100];

		Brain(void);
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain(void);
};

#endif
