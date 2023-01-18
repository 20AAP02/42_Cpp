CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror -Wimplicit-fallthrough=0
RM			= 	/bin/rm -f
NAME		= 	harlFilter

INCLUDES	=	./
SRCS		=	$(shell find ./ -name "*.cpp")

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(SRCS)

fclean:
	@$(RM) $(NAME)

re: fclean all

e: re
	@./$(NAME)

.PHONY: all fclean re e