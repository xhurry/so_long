# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 00:52:56 by alexamar          #+#    #+#              #
#    Updated: 2022/09/13 05:43:19 by alexamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long

CC			= 		gcc

CCFLAGS		=		-Wall -Werror -Wextra

MLXFLAGS	=		-lmlx -lX11 -lXext

PRINTF_PATH	=		./ft_printf

PRINTF		=		$(PRINTF_PATH)/libftprintf.a

RM			=		rm -rf

VALGRIND	=		valgrind --leak-check=full --show-leak-kinds=all
					--log-file="valgrind_log.txt"

SOURCE		=		so_long.c \
					$(addprefix utils/, ft_read_map.c ft_validate_map.c \
										ft_init.c ft_events.c \
										ft_game.c ft_put_image.c)

OBJ			=		$(SOURCE:%.c=%.o)

all:				$(NAME)

$(NAME):			$(OBJ)
					$(MAKE) -C $(PRINTF_PATH)
					$(CC) $(CCFLAGS) $(OBJ) $(PRINTF) $(MLXFLAGS) -o $(NAME)

clean:
					$(MAKE) -C $(PRINTF_PATH) clean
					$(RM) $(OBJ)

fclean:				clean
					$(MAKE) -C $(PRINTF_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re