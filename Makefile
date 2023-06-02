SRCS = main.c \
       map.c \
       tools.c \
       path.c \
       get_next_line/get_next_line.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   libft/ft_memcpy.c \
	   libft/ft_putstr_fd.c \
       libft/ft_strncmp.c \
	   libft/ft_strchr.c \
	   libft/ft_strlcpy.c \
	   libft/ft_split.c \
	   libft/ft_substr.c \
	   libft/ft_strjoin.c 

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
NAME			= so_long

all:			shifuuu $(NAME)
				@echo "\033[1m\033[32mCompilation has completed"

$(NAME) : $(OBJS) so_long.h get_next_line/get_next_line.h libft/libft.h
	${CC} ${CFLAGS} ${OBJS} -o $(NAME)

clean:
				$(RM) $(OBJS) 
				@echo "\033[1m\033[31mObject files removed"

fclean:			
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