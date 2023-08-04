/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/02 17:10:17 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(void){
	// std::cout << "Default constructor called\n";
	this->grade = 0;
	this->name = "default";
	this->sign = 0;
	this->exec_grade = 0;
}

AForm::AForm(std::string name, int grade, bool sign, int exec_grade){
	this->grade = grade;
	this->name = name;
	this->sign = sign;
	this->exec_grade = exec_grade;
	try{
		if(grade > 150 || grade < 1)
			throw (grade);
	}
	catch (int grade){
		if (grade > 150){
			GradeTooHighException(*this);
			this->setGrade(150);
		}
		else{
			GradeTooLowException(*this);
			this->setGrade(1);
		}
	}
}

void	AForm::GradeTooHighException(AForm &a){
	std::cout << a << " is too high\n";
	a.setGrade(150);
}

void	AForm::GradeTooLowException(AForm &a){
	std::cout << a << " is too Low\n";
}

std::string AForm::getName(void)const{
	return name;
}

int AForm::getGrade(void)const{
	return grade;
}

bool AForm::getsign(void) const{
	return sign;
}

int AForm::getexecgrade(void) const {
	return exec_grade;
}

void AForm::setGrade(int const grade){
	this->grade = grade;
}

AForm::~AForm(void){
	// std::cout << "Destructor called\n";
}

AForm& AForm::operator=(const AForm& a)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &a) {
		grade = a.grade;
		name = a.name;
		sign = a.sign;
		exec_grade = a.exec_grade;
	}
	return *this;
}

AForm::AForm(const AForm& a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}

std::ostream& operator<<(std::ostream& out, const AForm& a){
	out << a.getName() << " grade " << a.getGrade();
	return (out);
}

void	AForm::beSigned(Bureaucrat &a){
	try{
		if (a.getGrade() > this->getGrade())
			throw (this->getGrade());
		this->sign = 1;
	}
	catch (int grade){
		std::cout << "beacause of form grade is " << grade << " ";
		a.GradeTooLowException(a);
	}
}