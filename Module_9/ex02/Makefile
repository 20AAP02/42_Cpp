CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	PmergeMe

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
	@./$(NAME)

v: cls re cls
	@valgrind ./$(NAME)

.PHONY: all clean fclean re e cls v