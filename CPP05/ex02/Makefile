NAME	= Bureaucrat

SRC		= main.cpp \
		  Bureaucrat.cpp \
		  AForm.cpp \
		  PresidentialPardonForm.cpp \
		  RobotomyRequestForm.cpp \
		  ShrubberyCreationForm.cpp

OBJ		= $(SRC:%.cpp=%.o)

FLAGS	= -Wall -Wextra -Werror
CPP		= c++ -std=c++98

all:		$(NAME)

$(NAME):	$(OBJ) Makefile
			$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o:		%.cpp
			$(CPP) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re