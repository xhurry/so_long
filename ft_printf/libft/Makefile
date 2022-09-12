# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 14:05:19 by alexamar          #+#    #+#              #
#    Updated: 2022/09/12 17:48:16 by alexamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c ft_strlcat.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c  ft_strnstr.c \
					ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
					ft_newstrjoin.c get_next_line.c\

OBJS		=		$(SRCS:.c=.o)

CC			=		clang

CFLAGS		=		-Wall -Wextra -Werror

AR			=		ar

ARFLAGS		=		rcs

RM			=		rm -f

NAME		=		libft.a

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		re fclean clean all
