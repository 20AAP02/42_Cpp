CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	sed

INCLUDES	=	./
SRCS		=	./main.cpp ./fileReplace.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(SRCS)

fclean:
	@$(RM) $(NAME)

re: fclean all

e: re
	@./$(NAME)

.PHONY: all fclean re e