/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:31 by migo              #+#    #+#             */
/*   Updated: 2023/08/02 17:10:17 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
#include <fstream>


void drawtree(std::string name);

ShrubberyCreationForm::ShrubberyCreationForm(void) 
: AForm("ShrubberyCreationForm", 145, 0, 137)
{
	//std::cout << "123\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) 
: AForm(name, 145, 0, 137)
{
	//std::cout << "123\n";
}



ShrubberyCreationForm::~ShrubberyCreationForm(void){
	// std::cout << "Destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try{
		if (this->sign == false)
			throw (false);
		if (executor.getGrade() > this->exec_grade)
			throw (executor.getGrade());
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		drawtree(executor.getName());
	}
	catch (bool a){
		std::cout << "is not signed\n";
	}
	catch (int grade){
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " beacuse ";
		std::cout << executor.getGrade() << " is too low\n";
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& a)
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a)
{
	// std::cout << "Copy constructor called\n";
	*this = a;
}

void drawtree(std::string name){
	 std::ofstream out(name + "_shrubbery");
	 if (!out.is_open()) {
		std::cerr << "파일을 열 수 없습니다." << std::endl;
		return;
		}
		
		int height = 10;
		
		for (int i = 1; i <= height; i++) {
			for (int j = 0; j < height - i; j++) {
				out << " ";
				}
				for (int j = 0; j < 2 * i - 1; j++) {
					out << "*";
					}		
					out << std::endl;
					}
					for (int i = 0; i < height - 1; i++) {
						out << " ";
						}
						out << "|" << std::endl;
						return ;
}