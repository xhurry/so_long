/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:33:00 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 17:50:07 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_save_next(char	*fsave)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (fsave[i] != '\0' && fsave[i] != '\n')
		i++;
	if (fsave[i] == '\0')
	{
		free (fsave);
		return (NULL);
	}
	buff = (char *)malloc(sizeof(char) * (ft_strlen(fsave) - i + 1));
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (fsave[i])
		buff[j++] = fsave[i++];
	buff[j] = '\0';
	free (fsave);
	return (buff);
}

char	*ft_getline(char	*fsave)
{
	char	*buff;
	int		i;

	i = 0;
	if (fsave[i] == '\0')
		return (NULL);
	while (fsave[i] != '\n' && fsave[i] != '\0')
		i++;
	buff = (char *)malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (NULL);
	i = 0;
	while (fsave[i] != '\0' && fsave[i] != '\n')
	{
		buff[i] = fsave[i];
		i++;
	}
	if (fsave[i] == '\n')
	{
		buff[i] = fsave[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_read_file(int fd, char *fsave)
{
	char	*buff;
	int		len;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(fsave, '\n') && len != 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		fsave = ft_newstrjoin(fsave, buff);
	}
	free(buff);
	return (fsave);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fsave;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fsave = ft_read_file(fd, fsave);
	if (!fsave)
		return (NULL);
	line = ft_getline(fsave);
	fsave = ft_save_next(fsave);
	return (line);
}
