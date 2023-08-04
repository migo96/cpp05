/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/02 17:10:17 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
#include<cstdlib>
#include<ctime>


void Robotomy(std::string name);

RobotomyRequestForm::RobotomyRequestForm(void) 
: AForm("RobotomyRequestForm", 72, 0, 45)
{
	//std::cout << "123\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) 
: AForm(name, 72, 0, 45)
{
	//std::cout << "123\n";
}



RobotomyRequestForm::~RobotomyRequestForm(void){
	// std::cout << "Destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	try{
		if (this->sign == false)
			throw (false);
		if (executor.getGrade() > this->exec_grade)
			throw (executor.getGrade());
		Robotomy(executor.getName());
	}
	catch (bool a){
		std::cout << "is not signed\n";
	}
	catch (int grade){
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " beacuse ";
		std::cout << executor.getGrade() << " is too low\n";
	}
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& a)
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a)
:AForm(a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}

void Robotomy(std::string name){
	 std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand();
    if (randomNumber % 2 == 0) {
        std::cout << name << " robotization succuess" << std::endl;
    } else {
        std::cout << name << " robotization failed" << std::endl;
    }


}