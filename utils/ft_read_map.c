/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:47:59 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/13 05:47:11 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_empty_map(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\0')
	{
		free(map);
		return (0);
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] != '1')
		{
			free(map);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_read_map(char *path)
{
	int		fd;
	char	*line;
	char	*temp_map;
	char	*map;
	char	**map_final;

	fd = open(path, O_RDONLY);
	if (fd < 0)
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
	if (!ft_empty_map(map))
		return (NULL);
	map_final = (ft_split(map, '\n'));
	free(map);
	return (map_final);
}
