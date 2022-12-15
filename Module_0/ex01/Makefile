CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	megaphone

SRCS		=	$(shell find ./ -name "*.cpp")

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

fclean:
	@$(RM) $(NAME)

re: fclean all

e: re
	@./$(NAME) Hello world
	@./$(NAME) Hello " world" !
	@./$(NAME) Hello " world " 'lol' ' !!! '
	@./$(NAME)

.PHONY: all fclean re e