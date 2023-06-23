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
MLXF		= -Imlx -lmlx -framework OpenGL -framework AppKit
NAME			= so_long

all:			shifuuu $(NAME)
				@echo "\033[1m\033[32mCompilation has completed"

$(NAME) : $(OBJS) ${HDRS}
	${CC} ${CFLAGS} ${MLXF} ${OBJS} -o $(NAME)

clean:
				clear
				$(RM) $(OBJS) 
				@echo "\033[1m\033[31mObject files removed"

fclean:			
				clear
				$(RM) $(OBJS)
				$(RM) $(NAME)
				@echo "\033[1m\033[31mThe executable file and object files have been successfully removed"

re:				fclean all

shifuuu:
			clear
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