/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:02:48 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 05:47:08 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_player(t_program *program, int y, int x)
{
	program->player.x = x;
	program->player.y = y;
	mlx_put_image_to_window(program->mlx, program->window,
		program->player.img_ptr, x * XPM, y * XPM);
}

void	ft_put_wall(t_program *program, int y, int x)
{
	mlx_put_image_to_window(program->mlx, program->window,
		program->wall.img_ptr, x * XPM, y * XPM);
}

void	ft_put_floor(t_program *program, int y, int x)
{
	mlx_put_image_to_window(program->mlx, program->window,
		program->floor.img_ptr, x * XPM, y * XPM);
}

void	ft_put_collect(t_program *program, int y, int x)
{
	mlx_put_image_to_window(program->mlx, program->window,
		program->collect.img_ptr, x * XPM, y * XPM);
}

void	ft_put_exit(t_program *program, int y, int x)
{
	mlx_put_image_to_window(program->mlx, program->window,
		program->exit.img_ptr, x * XPM, y * XPM);
}
