SRCS	= ft_printf.c \
			ft_format_c.c \
			ft_format_d.c \
			ft_format_p.c \
			ft_format_s.c \
			ft_format_u.c \
			ft_format_x.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

AR		= ar
ARFLAGS	= rc

all:		$(NAME)

$(NAME): 	$(OBJS)
				$(AR) $(ARFLAGS) $@ $^

$(OBJS):	%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(NAME)

clean:		
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re