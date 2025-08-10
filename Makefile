NAME = pipex

SRCS = main.c errors.c parse.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS += -Wall -Werror -Wextra

GREEN  := \033[0;32m
RED    := \033[0;31m
YELLOW := \033[1;33m
RESET  := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)\n COMPILATION DONE \n$(RESET)"

clean: 
	@rm -f $(OBJS)
	@echo "$(YELLOW)\n OBJECTS REMOVED $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)\n EXECUTABLES REMOVED $(RESET)"

re: fclean all

.PHONY: all clean fclean re