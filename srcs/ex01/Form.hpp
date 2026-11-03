/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:34:58 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 15:34:58 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;

	public:
		Form();
		Form( const std::string& name, int GradeToSign, int GradeToExec );
		Form( const Form& form );
		~Form();
		Form&	operator=( const Form& rhs );

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

		void				beSigned( const Bureaucrat& bureaucrat );

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
};

std::ostream&		operator<<( std::ostream& os, const Form& form );

#endif
