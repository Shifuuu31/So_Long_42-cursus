SRCS = main.c \
       map.c \
       tools.c \
       tools_2.c \
       path.c \
       window.c \
       move.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   libft/ft_memcpy.c \
	   libft/ft_memset.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_putnbr_fd.c \
       libft/ft_strncmp.c \
	   libft/ft_strchr.c \
	   libft/ft_strlcpy.c \
	   libft/ft_split.c \
	   libft/ft_substr.c \
	   libft/ft_strjoin.c 

OBJS			= $(SRCS:.c=.o)
HDRS			=	so_long.h \
					libft/libft.h
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
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

.PHONY: all clean fclean re shifuuu