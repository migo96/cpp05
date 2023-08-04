/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/02 17:10:17 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form(void){
	// std::cout << "Default constructor called\n";
	this->grade = 0;
	this->name = "default";
	this->sign = 0;
}

Form::Form(std::string name, int grade){
	this->grade = grade;
	this->name = name;
	this->sign = 0;
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

void	Form::GradeTooHighException(Form &a){
	std::cout << a << " is too high\n";
	a.setGrade(150);
}

void	Form::GradeTooLowException(Form &a){
	std::cout << a << " is too Low\n";
}

std::string Form::getName(void)const{
	return name;
}

int Form::getGrade(void)const{
	return grade;
}

void Form::setGrade(int const grade){
	this->grade = grade;
}

Form::~Form(void){
	// std::cout << "Destructor called\n";
}

Form& Form::operator=(const Form& a)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &a) {
		grade = a.grade;
		name = a.name;
		sign = a.sign;
	}
	return *this;
}

Form::Form(const Form& a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}

std::ostream& operator<<(std::ostream& out, const Form& a){
	out << a.getName() << " grade " << a.getGrade();
	return (out);
}

void	Form::beSigned(Bureaucrat &a){
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