/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:11:31 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 04:03:47 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arg(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strlen(ft_strrchr(argv[1], '.')) == 4)
		{
			if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
			{
				ft_printf("Error!\nWrong extension!\n");
				exit(1);
			}
		}
		else
		{
			ft_printf("Error!\nWrong extension!\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error!\nWrong number of arguments!\n");
		exit(1);
	}
}

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

int	main(int argc, char *argv[])
{
	t_program	program;
	int			y;

	y = 0;
	ft_check_arg(argc, argv);
	program.map = ft_read_map(argv[1]);
	if (!program.map)
	{
		ft_printf("Error!\nInvalid map or map could not be readed.\n");
		return (0);
	}
	if (ft_validate_map(&program) == 1)
	{
		ft_free_map(program.map);
		return (0);
	}
	ft_init(&program);
	ft_draw(&program);
	ft_game(&program);
	mlx_loop(program.mlx);
	return (0);
}
