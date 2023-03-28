CC			= 	c++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	RPN

INCLUDES	=	./
SRCS		=	$(shell find ./ -name '*.cpp')

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(SRCS)

clean:

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Completary

cls:
	@clear

e: cls re cls
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

v: cls re cls
	@valgrind ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

.PHONY: all clean fclean re e cls v