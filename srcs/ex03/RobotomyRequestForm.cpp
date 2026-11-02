/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm("Robotomy request", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& form )
	: AForm(form)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs )
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::performAction() const
{
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed for " << getTarget() << "." << std::endl;
}
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:30:19 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 19:30:19 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

