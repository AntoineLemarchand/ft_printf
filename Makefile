SRCS		= $(addprefix srcs/, \
			  	hex_manager.c \
			  	nbr_manager.c \
				ft_printf.c \
				)


OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I includes

%.c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o} -L libft -l lift

all:		${NAME}

lib: 
			make -C libft
			cp libft/includes/libft.h includes

${NAME}:	lib ${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:	
			make fclean -C libft/
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
