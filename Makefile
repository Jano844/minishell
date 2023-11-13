CC = cc
#CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline
NAME = minishell

SRCS = test.c check_input.c get_path.c list_utils.c temp.c utils.c execute.c

OBJS = $(SRCS:.c=.o)

LIBFT_REPO = https://github.com/Jano844/42Project01.git
LIBFT_DIR = libft
LIBFT_MAKE = $(LIBFT_DIR)/Makefile
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

PRINTF_REPO = https://github.com/Jano844/ft_printf.git
PRINTF_DIR = ft_printf
PRINTF_MAKE = $(PRINTF_DIR)/Makefile
PRINTF_TARGET = $(PRINTF_DIR)/libftprintf.a13.376935

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_TARGET) $(PRINTF_TARGET)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(LDFLAGS)

$(LIBFT_TARGET):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		echo "Cloning libft repository..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_TARGET):
	@if [ ! -d $(PRINTF_DIR) ]; then \
		echo "Cloning ft_printf repository..."; \
		git clone $(PRINTF_REPO) $(PRINTF_DIR); \
	fi
	@$(MAKE) -C $(PRINTF_DIR)

# Add $(LIBFT_TARGET) and $(PRINTF_TARGET) as prerequisites for $(OBJS)
$(OBJS): $(LIBFT_TARGET) $(PRINTF_TARGET)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
