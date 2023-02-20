CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	bureaucrat
FILES		=	$(shell find ./ -name '*_shrubbery')

INCLUDES	=	./
SRCS		=	$(shell find ./ -name '*.cpp')

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(SRCS)

clean:
	@$(RM) $(FILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

cls:
	@clear

e: cls re cls
	@./$(NAME)

v: cls re cls
	@valgrind ./$(NAME)

.PHONY: all clean fclean re e cls v