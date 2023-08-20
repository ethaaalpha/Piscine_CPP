#---------------------------------------------------#
CC 			= c++

CFLAGS 		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

NAME 		= ex03
#---------------------------------------------------#
OBJ_DIR 	= obj/

SRCS		= \
main.cpp\
AMateria.cpp\
Character.cpp\
Cure.cpp\
Ice.cpp\

OBJ_DIR 	= .obj

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

HEADERS		= \
AMateria.hpp\
Character.hpp\
Cure.hpp\
Ice.hpp\
ICharacter.hpp\
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
