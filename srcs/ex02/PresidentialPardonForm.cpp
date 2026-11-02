/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm("Presidential pardon", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& form )
	: AForm(form)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs )
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void PresidentialPardonForm::performAction() const
{
	std::cout << getTarget()
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:30:28 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 19:30:28 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

