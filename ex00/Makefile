NAME = a.out

SRCS = Bureaucrat.cpp main.cpp 
OBJS = Bureaucrat.o main.o 

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