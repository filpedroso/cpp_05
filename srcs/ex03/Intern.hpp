/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:16:55 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/02 18:16:55 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
	static AForm*	createShrubbery( const std::string& target );
	static AForm*	createRobotomy( const std::string& target );
	static AForm*	createPresidential( const std::string& target );

	public:

		Intern();
		Intern( const Intern& intern );
		~Intern();
		Intern&	operator=( const Intern& rhs );

		AForm*	makeForm( const std::string& formName, const std::string& target );
};

#endif
