SRCS		= $(addprefix srcs/, \
			  	str_manager.c \
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
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
