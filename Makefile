SRCS = src/main.c \
       src/map.c \
       src/tools.c \
       src/tools_2.c \
       src/path.c \
       src/window.c \
       src/move.c \
       src/libft/ft_strlen.c \
       src/libft/ft_strdup.c \
       src/libft/ft_memcpy.c \
       src/libft/ft_memset.c \
       src/libft/ft_putchar_fd.c \
       src/libft/ft_putstr_fd.c \
       src/libft/ft_putnbr_fd.c \
       src/libft/ft_strncmp.c \
       src/libft/ft_strchr.c \
       src/libft/ft_strlcpy.c \
       src/libft/ft_split.c \
       src/libft/ft_substr.c \
       src/libft/ft_strjoin.c 

OBJS			= $(SRCS:.c=.o)
HDRS			= header/so_long.h \
				  header/libft.h
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -Iheader
UNAME			= $(shell uname)

ifeq ($(UNAME), Darwin)
MLXF			= -Imlx -lmlx -framework OpenGL -framework AppKit
CFLAGS			+= -Imlx
else
MLX_DIR			= minilibx-linux
MLX_LIB			= $(MLX_DIR)/libmlx.a
MLXF			= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
CFLAGS			+= -I$(MLX_DIR)
endif

NAME			= so_long

all:			shifuuu $(NAME)
				@echo "\033[1m\033[32mCompilation has completed\033[0m"

ifeq ($(UNAME), Darwin)
$(NAME) : $(OBJS) ${HDRS}
	${CC} ${CFLAGS} ${MLXF} ${OBJS} -o $(NAME)
else
$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME) : $(OBJS) ${HDRS} $(MLX_LIB)
	${CC} ${CFLAGS} ${OBJS} ${MLXF} -o $(NAME)
endif

%.o: %.c ${HDRS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
				@clear 2>/dev/null || true
				$(RM) $(OBJS) 
				@echo "\033[1m\033[31mObject files removed\033[0m"

fclean:			
				@clear 2>/dev/null || true
				$(RM) $(OBJS)
				$(RM) $(NAME)
				@echo "\033[1m\033[31mThe executable file and object files have been successfully removed\033[0m"

re:				fclean all

shifuuu:
			@clear 2>/dev/null || true
			@echo "	\033[37m░██████╗██╗░░██╗██╗███████╗██╗░░░██╗██╗░░░██╗██╗░░░██╗"
			@echo "	\033[37m██╔════╝██║░░██║██║██╔════╝██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m╚█████╗░███████║██║█████╗░░██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m░╚═══██╗██╔══██║██║██╔══╝░░██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m██████╔╝██║░░██║██║██║░░░░░╚██████╔╝╚██████╔╝╚██████╔╝"
			@echo "	\033[37m╚═════╝░╚═╝░░╚═╝╚═╝╚═╝░░░░░░╚═════╝░░╚═════╝░░╚═════╝░"
			@echo "	\033[37m														 "
			@echo "	\033[37m███╗░░░███╗░█████╗░░██████╗████████╗███████╗██████╗░"
			@echo "	\033[37m████╗░████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗"
			@echo "	\033[37m██╔████╔██║███████║╚█████╗░░░░██║░░░█████╗░░██████╔╝"
			@echo "	\033[37m██║╚██╔╝██║██╔══██║░╚═══██╗░░░██║░░░██╔══╝░░██╔══██╗"
			@echo "	\033[37m██║░╚═╝░██║██║░░██║██████╔╝░░░██║░░░███████╗██║░░██║"
			@echo "	\033[37m╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝"
			@echo "															 "

test:
				@make -C tests

.PHONY: all clean fclean re shifuuu test