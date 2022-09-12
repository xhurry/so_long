/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:29:51 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 14:41:54 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_program *program)
{
	if (program->map[program->player.y][program->player.x] == 'E' \
		&& program->n_collect == 0)
	{
		program->n_moves += 1;
		ft_printf("\nmoves = %d", program->n_moves);
		ft_win(program);
	}
	else if (program->map[program->player.y][program->player.x] == '1' \
		|| program->map[program->player.y][program->player.x] == 'E')
		program->player.y += 1;
	else
	{
		if (program->map[program->player.y][program->player.x] == 'C')
			program->n_collect--;
		program->map[program->player.y][program->player.x] = 'P';
		program->map[program->player.y + 1][program->player.x] = '0';
		{
			program->n_moves += 1;
			ft_printf("\nmoves = %d", program->n_moves);
			ft_draw(program);
		}
	}
}

void	ft_move_left(t_program *program)
{
	if (program->map[program->player.y][program->player.x] == 'E'
			&& program->n_collect == 0)
	{
		program->n_moves += 1;
		ft_printf("\nmoves = %d", program->n_moves);
		ft_win(program);
	}
	else if (program->map[program->player.y][program->player.x] == '1' \
		|| program->map[program->player.y][program->player.x] == 'E')
		program->player.x += 1;
	else
	{
		if (program->map[program->player.y][program->player.x] == 'C')
			program->n_collect--;
		program->map[program->player.y][program->player.x] = 'P';
		program->map[program->player.y][program->player.x + 1] = '0';
		{
			program->n_moves += 1;
			ft_printf("\nmoves = %d", program->n_moves);
			ft_draw(program);
		}
	}
}

void	ft_move_down(t_program *program)
{
	if (program->map[program->player.y][program->player.x] == 'E' \
		&& program->n_collect == 0)
	{
		program->n_moves += 1;
		ft_printf("\nmoves = %d", program->n_moves);
		ft_win(program);
	}
	else if (program->map[program->player.y][program->player.x] == '1' \
		|| program->map[program->player.y][program->player.x] == 'E')
		program->player.y -= 1;
	else
	{
		if (program->map[program->player.y][program->player.x] == 'C')
			program->n_collect--;
		program->map[program->player.y][program->player.x] = 'P';
		program->map[program->player.y - 1][program->player.x] = '0';
		{
			program->n_moves += 1;
			ft_printf("\nmoves = %d", program->n_moves);
			ft_draw(program);
		}
	}
}

void	ft_move_right(t_program *program)
{
	if (program->map[program->player.y][program->player.x] == 'E' \
		&& program->n_collect == 0)
	{
		program->n_moves += 1;
		ft_printf("\nmoves = %d", program->n_moves);
		ft_win(program);
	}
	else if (program->map[program->player.y][program->player.x] == '1' \
		|| program->map[program->player.y][program->player.x] == 'E')
		program->player.x -= 1;
	else
	{
		if (program->map[program->player.y][program->player.x] == 'C')
			program->n_collect--;
		program->map[program->player.y][program->player.x] = 'P';
		program->map[program->player.y][program->player.x - 1] = '0';
		{
			program->n_moves += 1;
			ft_printf("\nmoves = %d", program->n_moves);
			ft_draw(program);
		}
	}
}

int	ft_moves(int key, t_program *program)
{
	if (key == W)
	{
		program->player.y -= 1;
		ft_move_up(program);
	}
	else if (key == A)
	{
		program->player.x -= 1;
		ft_move_left(program);
	}
	else if (key == S)
	{
		program->player.y += 1;
		ft_move_down(program);
	}
	else if (key == D)
	{
		program->player.x += 1;
		ft_move_right(program);
	}
	return(0);
}
