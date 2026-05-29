NAME	= ROBOTSSS

GCC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp

all: $(NAME)

$(NAME):
	$(GCC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Theres only executable, execute make fclean."

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re