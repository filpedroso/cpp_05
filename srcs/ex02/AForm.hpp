/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:34:58 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 15:34:58 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
	
	protected:
		virtual void	performAction() const = 0;

	public:
		AForm();
		AForm( const std::string& name, const std::string& target, int gradeToSign, int gradeToExec );
		AForm( const AForm& form );
		virtual ~AForm();
		AForm&	operator=( const AForm& rhs );

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned( const Bureaucrat& bureaucrat );
		void				execute( const Bureaucrat& executor ) const;


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


std::ostream&		operator<<( std::ostream& os, const AForm& form );


#endif
