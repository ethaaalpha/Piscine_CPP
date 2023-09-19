#---------------------------------------------------#
CC 			= c++

CFLAGS 		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

NAME 		= ex02
#---------------------------------------------------#
SRCS		= \
main.cpp\
Bureaucrat.cpp\
Form.cpp\
ShrubberyCreationForm.cpp\
RobotomyRequestForm.cpp\
PresidentialPardonForm.cpp

OBJ_DIR 	= .obj

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

HEADERS		= \
Bureaucrat.hpp\
Form.hpp\
ShrubberyCreationForm.hpp\
RobotomyRequestForm.hpp\
PresidentialPardonForm.hpp
#---------------------------------------------------#
all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re
#---------------------------------------------------#
