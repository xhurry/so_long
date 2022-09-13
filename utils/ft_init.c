/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:26:37 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 05:47:06 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
				ft_put_wall(program, y, x);
			else if (program->map[y][x] == '0')
				ft_put_floor(program, y, x);
			else if (program->map[y][x] == 'E')
				ft_put_exit(program, y, x);
			else if (program->map[y][x] == 'C')
				ft_put_collect(program, y, x);
			else if (program->map[y][x] == 'P')
				ft_put_player(program, y, x);
			x++;
		}
		y++;
	}
}

void	ft_init(t_program	*program)
{
	program->mlx = mlx_init();
	program->window = mlx_new_window(program->mlx, (program->matrix.x) * XPM,
			(program->matrix.y) * XPM, "so_long");
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
