/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:22 by migo              #+#    #+#             */
/*   Updated: 2023/08/03 16:59:49 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
protected:
	int grade;
	int exec_grade;
	bool sign;
	std::string name;

public:
	void GradeTooHighException(AForm &a);
	void GradeTooLowException(AForm &a);
	std::string getName(void)const;
	int	getGrade(void)const;
	bool getsign(void)const;
	int getexecgrade(void) const;
	void setGrade(int const grade);
	void beSigned(Bureaucrat &a);
	virtual void execute(Bureaucrat const &executor) const = 0;
	AForm();
	AForm(std::string name, int grade, bool sign, int exec_grade);
	AForm(const AForm &a);
	AForm &operator= (const AForm &a);
	virtual ~AForm();

};
std::ostream& operator<<(std::ostream& out, const AForm& a);

# endif