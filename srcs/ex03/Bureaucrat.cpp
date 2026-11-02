/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:41:05 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 21:13:25 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade )
	: _name(name), _grade(grade)
{
	if (grade < highestGrade)
		throw GradeTooHighException();
	if (grade > lowestGrade)
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
	if (_grade <= highestGrade)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= lowestGrade)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm( AForm& form )
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout	<< this->_name
					<< " couldn't sign " << form.getName()
					<< " because " << ex.what()
					<< "." << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form ) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << this->_name
			<< " couldn't execute " << form.getName()
			<< " because " << ex.what()
			<< std::endl;
	}
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
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
