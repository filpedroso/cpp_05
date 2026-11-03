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
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

static void	processForm( Intern& intern, Bureaucrat& bureaucrat,
				const std::string& formName, const std::string& target )
{
	AForm*	form = intern.makeForm(formName, target);

	if (!form)
		return ;
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
}

int	main()
{
	std::srand(std::time(NULL));
	Intern		someRandomIntern;
	Bureaucrat	president("President", 1);
	Bureaucrat	clerk("Clerk", 140);

	std::cout << "--- Subject example ---" << std::endl;
	{
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	std::cout << "--- Every known form ---" << std::endl;
	processForm(someRandomIntern, president, "shrubbery creation", "office");
	processForm(someRandomIntern, president, "robotomy request", "Marvin");
	processForm(someRandomIntern, president, "presidential pardon", "Arthur Dent");

	std::cout << "--- Bureaucrat with a low grade ---" << std::endl;
	processForm(someRandomIntern, clerk, "presidential pardon", "Ford Prefect");

	std::cout << "--- Unknown forms ---" << std::endl;
	processForm(someRandomIntern, president, "coffee request", "Boss");
	processForm(someRandomIntern, president, "Robotomy Request", "Bender");
	processForm(someRandomIntern, president, "", "Nobody");

	std::cout << "--- Intern copy and assignment ---" << std::endl;
	Intern	copy(someRandomIntern);
	Intern	assigned;
	assigned = someRandomIntern;
	processForm(copy, president, "robotomy request", "Copy target");
	processForm(assigned, president, "shrubbery creation", "assigned");

	return 0;
}
