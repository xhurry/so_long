/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:12:55 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 05:47:03 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_program *program, int status)
{
	ft_free_image(program);
	mlx_destroy_window(program->mlx, program->window);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(status);
	return (0);
}

void	ft_win(t_program *program)
{
	if (program->map[program->player.y][program->player.x] == 'E' \
		&& program->n_collect == 0)
	{
		ft_printf("\nCongratulations, you won!\n");
		ft_exit(program, 0);
	}
}

int	ft_key_pressed(int key, t_program *program)
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
	mlx_hook(program->window, 2, 1L << 0, ft_key_pressed, program);
	mlx_hook(program->window, 17, (0L), ft_exit, program);
	mlx_hook(program->window, 12, (1L << 15), ft_move_window, program);
}
