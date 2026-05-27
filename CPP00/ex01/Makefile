NAME	= phonebook
WINDOW	= executables/phonebookwindow

GCC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS	= window.cpp PhoneBook.cpp Contact.cpp
MAIN	= main.cpp

all: $(NAME)

$(NAME): $(WINDOW)
	$(GCC) $(CFLAGS) $(MAIN) -o $(NAME)

$(WINDOW):
	@mkdir -p executables
	$(GCC) $(CFLAGS) $(SRCS) -o $(WINDOW)

clean:
	@echo "There's only executables."

fclean:
	rm -rf $(NAME) executables

re: fclean all

.PHONY: all clean fclean re