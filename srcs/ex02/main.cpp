/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:41:08 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 17:01:02 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(NULL));
	Bureaucrat intern("Intern", 150);
	Bureaucrat manager("Manager", 45);
	Bureaucrat president("President", 1);

	std::cout << "--- Unsigned execution ---" << std::endl;
	ShrubberyCreationForm unsignedForm("unsigned_test");
	std::cout << unsignedForm << std::endl;
	president.executeForm(unsignedForm);

	std::cout << "--- Shrubbery creation ---" << std::endl;
	ShrubberyCreationForm shrubbery("garden");
	intern.signForm(shrubbery);
	president.signForm(shrubbery);
	std::cout << shrubbery << std::endl;
	intern.executeForm(shrubbery);
	president.executeForm(shrubbery);

	std::cout << "--- Robotomy request ---" << std::endl;
	RobotomyRequestForm robotomy("Bender");
	manager.signForm(robotomy);
	std::cout << robotomy << std::endl;
	for (int i = 0; i < 4; ++i)
		manager.executeForm(robotomy);

	std::cout << "--- Presidential pardon ---" << std::endl;
	PresidentialPardonForm pardon("Arthur Dent");
	manager.signForm(pardon);
	president.signForm(pardon);
	std::cout << pardon << std::endl;
	manager.executeForm(pardon);
	president.executeForm(pardon);

	std::cout << "--- Through an AForm pointer ---" << std::endl;
	AForm*	form = new RobotomyRequestForm("R2-D2");
	president.signForm(*form);
	president.executeForm(*form);
	delete form;

	std::cout << "--- Copy and assignment ---" << std::endl;
	PresidentialPardonForm copy(pardon);
	PresidentialPardonForm assigned("Ford Prefect");
	assigned = pardon;
	std::cout << copy << std::endl;
	std::cout << assigned << std::endl;

	return 0;
}
