NAME	= fixed_point

GCC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= main.cpp Fixed.cpp Point.cpp

all: $(NAME)

$(NAME):
	$(GCC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Theres only executable, execute make fclean."

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re