SRCS		= $(addprefix srcs/, \
			    alpha_manager.c \
				nbr_manager.c \
				hex_manager.c \
				ft_printf.c \
				main.c \
				)


OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I includes

%.c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

lib: 
			make -C libft

${NAME}:	lib ${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:	
			make fclean -C libft/
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
