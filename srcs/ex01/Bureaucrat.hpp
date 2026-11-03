/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:31:21 by fpedroso          #+#    #+#             */
/*   Updated: 2026/10/31 15:11:32 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	const std::string	_name;
	int					_grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string& name, int grade );
		Bureaucrat( const Bureaucrat& bur );
		~Bureaucrat();
		Bureaucrat&	operator=( const Bureaucrat& rhs );

		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm( Form& form );

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

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif
