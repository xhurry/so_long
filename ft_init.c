/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:26:37 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 23:59:15 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_free_image(t_program *program)
{
	int	y;

	mlx_destroy_image(program->mlx, program->wall.img_ptr);
	mlx_destroy_image(program->mlx, program->collect.img_ptr);
	mlx_destroy_image(program->mlx, program->player.img_ptr);
	mlx_destroy_image(program->mlx, program->floor.img_ptr);
	mlx_destroy_image(program->mlx, program->exit.img_ptr);
	y = 0;
	while (program->map[y])
	{
		free(program->map[y]);
		y++;
	}
	free(program->map);
}

void	ft_draw(t_program *program)
{
	int	x;
	int	y;

	y = 0;
	while (program->map[y])
	{
		x = 0;
		while (program->map[y][x] != '\0')
		{
			if (program->map[y][x] == '1')
				mlx_put_image_to_window(program->mlx, program->window, \
					program->wall.img_ptr, x * XPM, y * XPM);
			else if (program->map[y][x] == '0')
				mlx_put_image_to_window(program->mlx, program->window, \
					program->floor.img_ptr, x * XPM, y * XPM);
			else if (program->map[y][x] == 'E')
				mlx_put_image_to_window(program->mlx, program->window, \
					program->exit.img_ptr, x * XPM, y * XPM);
			else if (program->map[y][x] == 'P')
			{
				program->player.x = x;
				program->player.y = y;
				mlx_put_image_to_window(program->mlx, program->window, \
					program->player.img_ptr, x * XPM, y * XPM);
			}
			else if (program->map[y][x] == 'C')
				mlx_put_image_to_window(program->mlx, program->window, \
					program->collect.img_ptr, x * XPM, y * XPM);
			x++;
		}
		y++;
	}
}

void	ft_init(t_program	*program)
{
	program->n_moves = 0;
	program->wall.img_ptr = mlx_xpm_file_to_image(program->mlx,
			"./images/wall.xpm", &program->wall.size_x, &program->wall.size_y);
	program->collect.img_ptr = mlx_xpm_file_to_image(program->mlx,
			"./images/collect.xpm", &program->collect.size_x,
			&program->collect.size_y);
	program->floor.img_ptr = mlx_xpm_file_to_image(program->mlx,
			"./images/floor.xpm", &program->floor.size_x,
			&program->floor.size_y);
	program->exit.img_ptr = mlx_xpm_file_to_image(program->mlx,
			"./images/exit.xpm", &program->exit.size_x, &program->exit.size_y);
	program->player.img_ptr = mlx_xpm_file_to_image(program->mlx,
			"./images/player.xpm", &program->player.size_x,
			&program->player.size_y);
}
