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
       ../src/map.c \
       ../src/tools.c \
       ../src/tools_2.c \
       ../src/path.c \
       ../src/libft/ft_strlen.c \
       ../src/libft/ft_strdup.c \
       ../src/libft/ft_memcpy.c \
       ../src/libft/ft_memset.c \
       ../src/libft/ft_putchar_fd.c \
       ../src/libft/ft_putstr_fd.c \
       ../src/libft/ft_putnbr_fd.c \
       ../src/libft/ft_strncmp.c \
       ../src/libft/ft_strchr.c \
       ../src/libft/ft_strlcpy.c \
       ../src/libft/ft_split.c \
       ../src/libft/ft_substr.c \
       ../src/libft/ft_strjoin.c

NAME = run_unit_tests

all: $(NAME)
	@./$(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -I../header $(SRCS) $(MLXF) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
