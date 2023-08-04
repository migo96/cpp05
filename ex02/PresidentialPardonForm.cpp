/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/02 17:10:17 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) 
: AForm("PresidentialPardonForm", 25, 0, 5)
{
	//std::cout << "123\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) 
: AForm(name, 25, 0, 5)
{
	//std::cout << "123\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	// std::cout << "Destructor called\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	try{
		if (this->sign == false)
			throw (false);
		if (executor.getGrade() > this->exec_grade)
			throw (executor.getGrade());
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox\n";
	}
	catch (bool a){
		std::cout << "is not signed\n";
	}
	catch (int grade){
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " beacuse ";
		std::cout << executor.getGrade() << " is too low\n";
	}
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& a)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &a) {
		grade = a.getGrade();
		name = a.getName();
		sign = a.getsign();
		exec_grade = a.getexecgrade();
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}