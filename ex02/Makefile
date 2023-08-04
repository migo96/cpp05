NAME = a.out

SRCS = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = Bureaucrat.o main.o AForm.o ShrubberyCreationForm.o RobotomyRequestForm.o PresidentialPardonForm.o

CXX = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) -o $@ $^

.cpp.o :
	$(CXX) -c -o $@ $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all