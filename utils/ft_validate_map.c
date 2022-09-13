/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:21:47 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 05:47:15 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_is_rectangular(t_program *program)
{
	int	y;
	int	x;

	y = 0;
	while (program->map[y])
	{
		if (ft_strlen(program->map[y]) != ft_strlen(program->map[0]))
			return (1);
		y++;
	}
	if (y <= 2)
		return (1);
	else
	{
		program->matrix.y = y;
		program->matrix.x = ft_strlen(program->map[0]);
		return (0);
	}
}

static int	ft_is_walled(char **map)
{
	int	y;
	int	x;
	int	len;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		y++;
		while (map[0][x] != '\0' && map[y - 1][x] != '\0')
		{
			if (map[0][x] != '1' || map[y - 1][x] != '1')
				return (1);
			x++;
		}
	}
	y = 1;
	len = ft_strlen(map[y]);
	while (map[y] != NULL)
	{
		if (map[y][0] != '1' || map[y][len - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

static int	ft_is_pec(t_program *program)
{
	int	y;
	int	x;

	y = 0;
	while (program->map[y] != NULL)
	{
		x = 0;
		while (program->map[y][x] != '\0')
		{
			if (program->map[y][x] == 'P')
				program->n_player++;
			else if (program->map[y][x] == 'E')
				program->n_exit++;
			else if (program->map[y][x] == 'C')
				program->n_collect++;
			else if (program->map[y][x] != '0' && program->map[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	if (program->n_player != 1 || program->n_exit == 0
		|| program->n_collect == 0)
		return (1);
	return (0);
}

int	ft_validate_map(t_program *program)
{
	if (ft_is_rectangular(program) == 0)
	{
		if (ft_is_walled(program->map) == 0)
		{
			program->n_collect = 0;
			program->n_player = 0;
			program->n_exit = 0;
			if (ft_is_pec(program) == 0)
				return (0);
		}
	}
	ft_printf("Error!\nInvalid map!\n");
	return (1);
}
