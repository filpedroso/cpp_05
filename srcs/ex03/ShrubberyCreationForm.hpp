/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:30:08 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 19:30:08 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	protected:
		virtual void	performAction() const;


	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& shrub );
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& rhs );


	class FileNotOpenException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

#endif
