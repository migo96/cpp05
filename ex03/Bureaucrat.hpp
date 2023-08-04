/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:22 by migo              #+#    #+#             */
/*   Updated: 2023/07/03 17:15:29 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
protected:
	int grade;
	std::string name;

public:
	Bureaucrat();
	void GradeTooHighException(Bureaucrat &a);
	void GradeTooLowException(Bureaucrat &a);
	void increaseGrade(void);
	void decreaseGrade(void);
	std::string getName(void)const;
	int	getGrade(void)const;
	void setGrade(int const grade);
	void signForm(AForm &a);
	void executeForm(AForm const &form); 
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &a);
	Bureaucrat &operator= (const Bureaucrat &a);
	~Bureaucrat();

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& a);

# endif