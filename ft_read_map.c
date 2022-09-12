/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:47:59 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 23:40:30 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *path)
{
	int		fd;
	char	*line;
	char	*temp_map;
	char	*map;
	char	**map_final;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_map = map;
		map = ft_strjoin(temp_map, line);
		free(line);
		free(temp_map);
	}
	ft_printf("mapa = %s", map);
	map_final = (ft_split(map, '\n'));
	free(map);
	return (map_final);
}
