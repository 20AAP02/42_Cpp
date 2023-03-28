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
	@./$(NAME) `shuf -i 1-100000 -n 100000 | tr "\n" " "`

v: cls re cls
	@valgrind ./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

.PHONY: all clean fclean re e cls v