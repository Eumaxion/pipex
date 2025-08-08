NAME = pipex

SRCS = main.c errors.c parse.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n------------- COMPILATION DONE -------------\n"

clean: 
	@rm -f $(OBJS)
	@echo "\n------------- OBJECTS REMOVED -------------\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n------------- EXECUTABLES REMOVED -------------\n"

re: fclean all

.PHONY: all clean fclean re