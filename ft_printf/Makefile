NAME	=	libftprintf.a

LIBFT_PATH	=	./libft
LIBFT	=	$(LIBFT_PATH)/libft.a

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

AR	=	ar
ARFLAGS	=	rcs

SOURCES	=		./ft_printf.c \
				./ft_char.c \
				./ft_hexadecimal.c \
				./ft_int.c \
				./ft_pointer.c \
				./ft_string.c \
				./ft_unsigned_int.c \

OBJECTS	=	$(SOURCES:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:	$(LIBFT) $(NAME)

$(LIBFT):
		make -C $(LIBFT_PATH)

$(NAME):	$(OBJECTS)
			cp $(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJECTS)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft