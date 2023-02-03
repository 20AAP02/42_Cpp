CC			= 	g++ -std=c++98
CFLAGS		= 	-Wall -Wextra -Werror -Wshadow -Wno-shadow
CSWITCH		=	-Wimplicit-fallthrough=0
RM			= 	/bin/rm -f
NAME		= 	animal

INCLUDES	=	./
SRCS		=	$(shell find ./ -name '*.cpp')

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(CSWITCH) -I$(INCLUDES) -o $(NAME) $(SRCS)

fclean:
	@$(RM) $(NAME)

re: fclean all

cls:
	@clear

e: cls re cls
	@./$(NAME)

v: cls re cls
	@valgrind ./$(NAME)

.PHONY: all fclean re e cls