CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
CSWITCH		=	-Wimplicit-fallthrough=0
RM			= 	/bin/rm -f
NAME		= 	fixed

INCLUDES	=	./
SRCS		=	./bsp.cpp ./Fixed.cpp ./main.cpp ./Point.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(CSWITCH) -I$(INCLUDES) -o $(NAME) $(SRCS)

fclean:
	@$(RM) $(NAME)

re: fclean all

e: re
	@./$(NAME)

get: re
	@./$(NAME) | tr -d -c 0-9
	@echo ""

.PHONY: all fclean re e