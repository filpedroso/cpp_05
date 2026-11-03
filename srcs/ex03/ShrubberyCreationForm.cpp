/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:30:12 by fpedroso          #+#    #+#             */
/*   Updated: 2026/11/01 19:30:12 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery", "Default", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: AForm("Shrubbery", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& shrub )
	: AForm(shrub)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs )
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::performAction() const
{
	std::string	filename = getTarget() + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw FileNotOpenException();

	file	<< "                              &  %&                                             \n"
			<< "                          #&@@&@&@#@                                            \n"
			<< "                        %&#%%#@#%#@&@@@ @@     &                                \n"
			<< "                        @ #@#&&%@#%@@%@@%#&%%# @&                               \n"
			<< "                        &%@#&@&#%&=&/&%#@@@&@@##@%@###&                         \n"
			<< "                        %#&#&#&#@@@#%%#@%%@@ %%%%@#&%&#_                        \n"
			<< "                     %@#&%&#@@#&&#|@@&%@%&/=;%@&%@% __%@%%                      \n"
			<< "                     @%%&@@@&@   \\|\\@@&&%/   ##%% @  &&@& @                   \n"
			<< "                   &## #@&@%&%#& #&#&%& %#  &##@&\\   @&@##                     \n"
			<< "                 @%&&#%@%#@## #%@%&%@|\\   %  %%@%&@%##& #                      \n"
			<< "               @@&@@#@%&%#/;@#_\\%@%=@&%%&   @%@@@& /                           \n"
			<< "                @@%@@&@%&@%&%@  ~&%#%&@#&  %   @&@#/% ##%                       \n"
			<< "              %%@@&&@@@_##=@&@@_%:#@&:@&      /;:;___%#__&#  % &                \n"
			<< "                 @@&@&#%%&#%  &   &@& &|    /////      :\\@@@@@@%%&@@@          \n"
			<< "                  # #% @   &   %       ;| ~///           &:&/%##&&&@            \n"
			<< "                    #       &           |;//             |#%  &%@@@&#           \n"
			<< "                                         |:=       @@%    / %@@#&@##%&          \n"
			<< "                                        ;||       &%%&&&| &&&%#% %  #%          \n"
			<< "                                        |=|        &@@&#&& & @ %&               \n"
			<< "                                        |~=       &#   &%@%%%%                  \n"
			<< "                                        |||           &&@&###                   \n"
			<< "                                       :|~            # # %                     \n"
			<< "                           \\_________./~||\\.--.______/                        \n"
			<< "                            \\        . ~      ~  .  /                          \n"
			<< "                             \\_____________________/                           \n"
			<< "                               -                 -                              \n";
}

const char*	ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return "File is not open";
}
