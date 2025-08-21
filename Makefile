NAME = pipex

SRCS = main.c errors.c validade_files.c ft_exec.c

BONUS_SRCS = bonus_main.c utils_here_doc.c errors.c validade_files.c ft_exec.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = ./libft/libft.a

CC = cc

CFLAGS += -Wall -Werror -Wextra

GREEN  := \033[0;32m
RED    := \033[0;31m
YELLOW := \033[1;33m
RESET  := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\n COMPILATION DONE ✅ \n$(RESET) "

bonus: $(BONUS_OBJS)
	@cd libft && make
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\n BONUS COMPILATION DONE ✅ \n$(RESET) "

.c.o:
	@$(CC) $(FLAGS) -c  $< -o ${<:.c=.o}

clean:
	@make -C libft clean
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)\n OBJECTS REMOVED $(RESET) ✅ \n"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(RED)\n EXECUTABLES REMOVED $(RESET) ✅ \n"

re: fclean all

.PHONY: bonus all clean fclean re