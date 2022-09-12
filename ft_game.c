/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:12:55 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 03:44:48 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_key_pressed(int	key, t_program *program)
{
	if (key == ESC)
		ft_exit(program, 0);
	else
		ft_moves(key, program);
	return (0);
}

int	ft_move_window(t_program *program)
{
	ft_draw(program);
	return (0);
}

void	ft_game(t_program *program)
{
	//manusear atalhos
	mlx_hook(program->window, 2, 1L<<0, ft_key_pressed, program);

	//fechar o programa
	mlx_hook(program->window, 17, (0L), ft_exit, program);

	//não perder imagem quando arrastar
	mlx_hook(program->window, 12, (1L << 15), ft_move_window, program);
}