NAME	= account

GCC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= tests.cpp Account.cpp

all: $(NAME)

$(NAME):
	$(GCC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "There's only executables."

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re