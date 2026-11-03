/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:35:01 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 17:00:48 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form( const std::string& name, int gradeToSign, int gradeToExec )
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	  _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form& form )
	: _name(form._name), _signed(form._signed),
	  _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec)
{
}

Form::~Form()
{
}

Form&	Form::operator=( const Form& rhs )
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

const std::string&	Form::getName() const
{
	return _name;
}

bool	Form::isSigned() const
{
	return _signed;
}

int	Form::getGradeToSign() const
{
	return _gradeToSign;
}

int	Form::getGradeToExec() const
{
	return _gradeToExec;
}

std::ostream& operator<<( std::ostream& os, const Form& form )
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to exec: " << form.getGradeToExec() << ".";
	return os;
}

void	Form::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}
