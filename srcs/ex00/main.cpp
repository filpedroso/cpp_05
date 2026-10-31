/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:41:08 by fpedroso          #+#    #+#             */
/*   Updated: 2026/10/31 15:54:50 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "--- Construction and output ---" << std::endl;
	Bureaucrat alice("Alice", 42);
	std::cout << alice << std::endl;

	std::cout << "--- Grade changes ---" << std::endl;
	Bureaucrat manager("Manager", 2);
	std::cout << manager << std::endl;
	manager.incrementGrade();
	std::cout << manager << std::endl;
	manager.decrementGrade();
	std::cout << manager << std::endl;

	std::cout << "--- Grade boundaries ---" << std::endl;
	try
	{
		Bureaucrat highest("Highest", 1);
		highest.incrementGrade();
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat lowest("Lowest", 150);
		lowest.decrementGrade();
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--- Invalid construction ---" << std::endl;
	try
	{
		Bureaucrat tooHigh("Too high", 0);
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("Too low", 151);
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--- Copy construction ---" << std::endl;
	Bureaucrat copy(alice);
	std::cout << copy << std::endl;

	std::cout << "--- Assignment ---" << std::endl;
	Bureaucrat assigned("Assigned", 100);
	std::cout << assigned << std::endl;
	assigned = alice;
	std::cout << assigned << std::endl;

	return 0;
}
