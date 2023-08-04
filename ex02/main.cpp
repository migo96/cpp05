/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:13 by migo              #+#    #+#             */
/*   Updated: 2023/08/03 17:24:34 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main( void ) {
	Bureaucrat person1("hun", 148);
	Bureaucrat person2("migo", 1);
	Bureaucrat person3("jun", 50);
	Bureaucrat person4("suho", 20);

	std::cout << person1 << std::endl;
	std::cout << person2 << std::endl;
	std::cout << person3 << std::endl;
	std::cout << person4 << std::endl;
	std::cout << std::endl;

	AForm *c = new ShrubberyCreationForm();
	AForm *d = new RobotomyRequestForm();
	AForm *e = new PresidentialPardonForm();

	
	person1.signForm(*c);
	person2.signForm(*c);
	std::cout << std::endl;

	person2.executeForm(*d);

	std::cout << std::endl;
	person2.signForm(*d);
	person2.signForm(*e);

	std::cout << std::endl;
	person1.executeForm(*c);

	std::cout << std::endl;
	person3.executeForm(*c);
	person3.executeForm(*d);
	
	std::cout << std::endl << "test radom" << std::endl;
	person4.executeForm(*d);

	std::cout << std::endl;
	person4.executeForm(*e);
	person2.executeForm(*e);
	delete c;
	delete d;
	delete e;
}