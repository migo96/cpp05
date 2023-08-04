/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:22 by migo              #+#    #+#             */
/*   Updated: 2023/07/03 17:15:29 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
private:
	int grade;
	bool sign;
	std::string name;

public:
	void GradeTooHighException(Form &a);
	void GradeTooLowException(Form &a);
	std::string getName(void)const;
	int	getGrade(void)const;
	void setGrade(int const grade);
	void beSigned(Bureaucrat &a);
	Form();
	Form(std::string name, int grade);
	Form(const Form &a);
	Form &operator= (const Form &a);
	~Form();

};
std::ostream& operator<<(std::ostream& out, const Form& a);

# endif