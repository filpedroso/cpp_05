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
#include "Form.hpp"

int	main()
{
	std::cout << "--- Form construction and output ---" << std::endl;
	Form leaveRequest("Leave request", 50, 25);
	std::cout << leaveRequest << std::endl;

	std::cout << "--- Signing forms ---" << std::endl;
	Bureaucrat employee("Employee", 75);
	Bureaucrat manager("Manager", 25);
	std::cout << employee << std::endl;
	std::cout << manager << std::endl;
	employee.signForm(leaveRequest);
	manager.signForm(leaveRequest);
	std::cout << leaveRequest << std::endl;

	std::cout << "--- Direct beSigned call ---" << std::endl;
	Form expenseReport("Expense report", 100, 50);
	try
	{
		expenseReport.beSigned(employee);
		std::cout << "Direct signing succeeded." << std::endl;
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << expenseReport << std::endl;

	std::cout << "--- Invalid form grades ---" << std::endl;
	try
	{
		Form tooHigh("Too high", 0, 50);
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tooLow("Too low", 50, 151);
	}
	catch ( const std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--- Form copy construction ---" << std::endl;
	Form copy(leaveRequest);
	std::cout << copy << std::endl;

	std::cout << "--- Form assignment ---" << std::endl;
	Form assigned("Assigned", 100, 100);
	std::cout << assigned << std::endl;
	assigned = leaveRequest;
	std::cout << assigned << std::endl;

	return 0;
}
