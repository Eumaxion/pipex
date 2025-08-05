NAME = pipex

SRCS = main.c

OBJ = $(SRCS:.c=.o)

CC = cc

FLAGS += -Wall -Werror -Wextra

all:

$(NAME):

clean: 

fclean: clean

re: fclean all

.PHONY: all clean fclean re