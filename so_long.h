/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 04:03:09 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 21:29:52 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//	minilibx
# include <mlx.h>

//	malloc e free
# include <stdlib.h>

// read e close
# include <unistd.h>

// open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// printf
# include "./ft_printf/ft_printf.h"

# define XPM	64
# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

typedef struct s_image {
	int		size_x;
	int		size_y;
	int		x;
	int		y;
	void	*img_ptr;
}				t_image;

typedef struct s_matrix {
	int		x;
	int		y;
}				t_matrix;

typedef struct s_program {
	void		*mlx;
	void		*window;
	char		**map;
	int			n_collect;
	int			n_player;
	int			n_exit;
	int			n_moves;
	t_matrix	matrix;
	t_image		wall;
	t_image		collect;
	t_image		floor;
	t_image		exit;
	t_image		player;
}				t_program;

char	**ft_read_map(char *path);
int		ft_validate_map(t_program *program);
int		ft_moves(int key, t_program *program);
int		ft_exit(t_program *program, int status);
int		ft_key_pressed(int key, t_program *program);
int		ft_move_window(t_program *program);
void	ft_init(t_program *program);
void	ft_draw(t_program *program);
void	ft_game(t_program *program);
void	ft_free_image(t_program *program);
void	ft_win(t_program *program);
void	ft_put_player(t_program *program, int y, int x);
void	ft_put_wall(t_program *program, int y, int x);
void	ft_put_floor(t_program *program, int y, int x);
void	ft_put_collect(t_program *program, int y, int x);
void	ft_put_exit(t_program *program, int y, int x);

#endif