PROG_NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c \
		k_input.c \
		map.c \
		so_long_utils.c \
		map_border_check.c \
		check.c \
		map_flood.c \
		map_gen.c \
		theme_select.c \
		movement.c \
		libft/ft_Printf/ft_printf.c \
		libft/ft_Printf/ft_putchar.c \
		libft/ft_Printf/ft_putnbr.c \
		libft/ft_Printf/ft_putnbrhex.c \
		libft/ft_Printf/ft_putstr.c

OBJS = $(SRCS:.c=.o)

#_____Define colors_____
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[1;33m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
#______________________

bold := $(shell tput bold)
notbold := $(shell tput sgr0)

#_____MESSAGES_____
define SUCCESS_MESSAGE
	@printf "\r${GREEN}$(bold)[$@ built successfully!]${NC}\n"
endef

define SUCCESS_MESSAGE_OBJS
	@printf "\r${GREEN}$(bold)[✔]${NC} $@ built successfully!"
endef

define CLEANING_SUCCESS
	@printf "\r${RED}$(bold)[🧹]${NC}$(bold)so_long cleaned successfully!\n"
endef
#__________________

$(PROG_NAME): $(OBJS)
	@make -s -C libft
	@$(CC) $(CFLAGS) $(OBJS) -o $@ MacroLibX/libmlx.so -lSDL2 -L ./libft -lft
	@echo -n "\033[2K"
	@$(call SUCCESS_MESSAGE, $(PROG_NAME))

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "\033[2K"
	@$(call SUCCESS_MESSAGE_OBJS, $@)

clean:
	@make -s clean -C libft
	@rm -f $(OBJS)
	@echo -n "\033[2K"
	@$(call CLEANING_SUCCESS)

fclean: clean
	@rm -f $(PROG_NAME)

re: fclean all

all: $(PROG_NAME)

.PHONY: all clean fclean re
