/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:11:31 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 23:16:56 by alexamar         ###   ########.fr       */
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
				ft_printf("Error\nWrong extension!\n");
				exit(1);
			}
		}
		else
		{
			ft_printf("Error\nWrong extension!\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error\nWrong number of arguments\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_program	program;
	int			y;

	y = 0;
	ft_check_arg(argc, argv);
	program.map = ft_read_map(argv[1]);
	if(!program.map)
	{
		ft_printf("Error\nThe map file was not found or could not be readed\n");
		return (0);
	}
	if(ft_validate_map(&program) == 1)
	{
		while (program.map[y])
		{
			free(program.map[y]);
			y++;
		}
		free(program.map);
		return(0);
	}

	//criando a janela
	program.mlx = mlx_init();
	program.window = mlx_new_window(program.mlx, (program.matrix.x)*XPM,
						(program.matrix.y)*XPM, "so_long");

	ft_init(&program);
	ft_draw(&program);
	ft_game(&program);
	mlx_loop(program.mlx);
	return (0);
}
