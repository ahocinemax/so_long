NAME        =    libft.a

CFLAGS         =    -Wall -Wextra -Werror -c

CC            =    gcc

SRCS        =   ft_atoi.c ft_itoa.c ft_putendl_fd.c \
                ft_bzero.c ft_putnbr_fd.c ft_strlen.c \
                ft_putstr_fd.c ft_strncmp.c ft_substr.c \
                ft_strjoin.c ft_putchar_fd.c ft_isdigit.c \
				ft_strcat.c

OBJS        =    $(SRCS:.c=.o)


all        :    $(NAME)

$(NAME)    : $(OBJS)
	ar rcs $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -f $(NAME)

re:            fclean all

.PHONY : re clean fclean all