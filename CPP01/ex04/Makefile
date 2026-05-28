NAME	= replace

GCC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= main.cpp

all: $(NAME)

$(NAME):
	$(GCC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Theres only executable, execute make fclean."

fclean:
	rm -rf $(NAME) *.replace

re: fclean all

.PHONY: all clean fclean re