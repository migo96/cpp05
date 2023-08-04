/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/02 17:10:17 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern(void) 
{
	//std::cout << "123\n";
}

Intern::~Intern(void){
	// std::cout << "Destructor called\n";
}

Intern& Intern::operator=(const Intern& a)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &a) {
	}
	return *this;
}

Intern::Intern(const Intern& a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}

AForm *Intern::makeForm(std::string form, std::string name){
	std::string a[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;

	for (i = 0; i < 3; i++){
		if (a[i] == form)
			break ;
	}
	switch (i){
		case 0:
			return (new ShrubberyCreationForm(name));
		case 1:
			return (new RobotomyRequestForm(name));
		case 2:
			return (new PresidentialPardonForm(name));
	}
	std::cout << form << " is not existed\n";
	exit (1);
}