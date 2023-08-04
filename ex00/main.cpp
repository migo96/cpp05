/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:54:13 by migo              #+#    #+#             */
/*   Updated: 2023/08/03 12:15:42 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main( void ) {
	Bureaucrat a("name", 150);
	Bureaucrat b("migo", 1);

	a.increaseGrade();
	b.decreaseGrade();

	a.decreaseGrade();
	b.increaseGrade();

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}