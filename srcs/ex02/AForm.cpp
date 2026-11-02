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

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( const std::string& name, const std::string& target, int gradeToSign, int gradeToExec ) :
	_name(name), _target(target), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExec < Bureaucrat::highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExec > Bureaucrat::lowestGrade)
		throw GradeTooLowException();
}

AForm::AForm( const AForm& form ) :
	_name(form._name), _target(form._target), _signed(false),
	_gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec)
{}

AForm::~AForm()
{}

// Name, target and grades are const, and the signature cannot be
// transferred by assignment (it must come from beSigned()).
// So assignment intentionally copies nothing.
AForm& AForm::operator=( const AForm& rhs )
{
	(void)rhs;
	return *this;
}

const std::string&	AForm::getName() const
{
	return _name;
}

const std::string&	AForm::getTarget() const
{
	return _target;
}

bool	AForm::isSigned() const
{
	return _signed;
}

int	AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int	AForm::getGradeToExec() const
{
	return _gradeToExec;
}

std::ostream& operator<<( std::ostream& os, const AForm& form )
{
	os << "Form " << form.getName()
		<< " (target: " << form.getTarget() << ")"
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to exec: " << form.getGradeToExec() << ".";
	return os;
}

void	AForm::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void AForm::execute( const Bureaucrat& executor ) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	performAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}
