/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:16:58 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/02 18:16:58 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern& intern )
{
	(void)intern;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=( const Intern& rhs )
{
	(void)rhs;
	return *this;
}

AForm*	Intern::createShrubbery( const std::string& target )
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomy( const std::string& target )
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidential( const std::string& target )
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm( const std::string& formName, const std::string& target )
{
	typedef AForm* (*Creator)( const std::string& );

	static const std::string	names[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	static const Creator		creators[3] = { &createShrubbery, &createRobotomy, &createPresidential };

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Intern couldn't create \"" << formName
		<< "\" because this form does not exist." << std::endl;
	return NULL;
}
