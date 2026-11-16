CC = cc
CFLAGS = -Wall -Wextra -Werror -g
UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
MLXF = -Imlx -lmlx -framework OpenGL -framework AppKit
CFLAGS += -Imlx
else
MLX_DIR = ../minilibx-linux
MLXF = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
CFLAGS += -I$(MLX_DIR)
endif

SRCS = unit_tests.c \
       ../map.c \
       ../tools.c \
       ../tools_2.c \
       ../path.c \
       ../libft/ft_strlen.c \
       ../libft/ft_strdup.c \
       ../libft/ft_memcpy.c \
       ../libft/ft_memset.c \
       ../libft/ft_putchar_fd.c \
       ../libft/ft_putstr_fd.c \
       ../libft/ft_putnbr_fd.c \
       ../libft/ft_strncmp.c \
       ../libft/ft_strchr.c \
       ../libft/ft_strlcpy.c \
       ../libft/ft_split.c \
       ../libft/ft_substr.c \
       ../libft/ft_strjoin.c

NAME = run_unit_tests

all: $(NAME)
	@./$(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -I.. -I../libft $(SRCS) $(MLXF) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
