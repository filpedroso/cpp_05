/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:41:05 by fpedroso          #+#    #+#             */
/*   Updated: 2026/10/31 15:41:05 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat( const std::string& name, int grade )
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& bur )
	: _name(bur._name), _grade(bur._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& rhs )
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}
