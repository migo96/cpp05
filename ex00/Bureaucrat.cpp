/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/03 13:56:26 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
	// std::cout << "Default constructor called\n";
	this->grade = 0;
	this->name = "default";
}

Bureaucrat::Bureaucrat(std::string name, int grade){
	this->grade = grade;
	this->name = name;
	try{
		if(grade > 150 || grade < 1)
			throw (grade);
	}
	catch (int grade){
		if (grade > 150)
			GradeTooLowException(*this);
		else
			GradeTooHighException(*this);
	}
}

void	Bureaucrat::GradeTooHighException(Bureaucrat &a){
	std::cout << a << " is too high\n";
	a.setGrade(1);
}

void	Bureaucrat::GradeTooLowException(Bureaucrat &a){
	std::cout << a << " is too Low\n";
	a.setGrade(150);
}

std::string Bureaucrat::getName(void)const{
	return name;
}

int Bureaucrat::getGrade(void)const{
	return grade;
}

void Bureaucrat::setGrade(int const grade){
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void){
	// std::cout << "Destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &a) {
		grade = a.grade;
		name = a.name;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a){
	out << a.getName() << " grade " << a.getGrade();
	return (out);
}

void	Bureaucrat::increaseGrade(void)
{
	grade++;
	try{
		if(grade > 150 || grade < 1)
			throw (grade);
	}
	catch (int grade){
		if (grade > 150)
			GradeTooLowException(*this);
		else
			GradeTooHighException(*this);
	}
}

void	Bureaucrat::decreaseGrade(void)
{
	grade--;
	try{
		if(grade > 150 || grade < 1)
			throw (grade);
	}
	catch (int grade){
		if (grade > 150)
			GradeTooLowException(*this);
		else
			GradeTooHighException(*this);
	}
}