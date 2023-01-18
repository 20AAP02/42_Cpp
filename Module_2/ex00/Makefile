CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror
CSWITCH		=	-Wimplicit-fallthrough=0
RM			= 	/bin/rm -f
NAME		= 	

INCLUDES	=	./
SRCS		=	./main.cpp ./Harl.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(CSWITCH) -I$(INCLUDES) -o $(NAME) $(SRCS)

fclean:
	@$(RM) $(NAME)

re: fclean all

e: re
	@./$(NAME)

.PHONY: all fclean re e