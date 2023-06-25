#---------------------------------------------------#
CC 			= c++

CFLAGS 		= -Wall -Wextra -Werror -std=c++98

NAME 		= ex01
#---------------------------------------------------#
OBJ_DIR 	= obj/

SRCS		= \
tests.cpp\
Account.cpp

OBJ_DIR 	= .obj

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADERS		= \
Account.hpp

#---------------------------------------------------#
all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c $(HEADERS)
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
