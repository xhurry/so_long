/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:19:18 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/12 04:17:00 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcounter(char const *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			wcount ++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (wcount);
}

static int	ft_len(char const *sw, char cw)
{
	size_t	i;

	i = 0;
	while (sw[i] != '\0' && sw[i] != cw)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		word_counter;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	word_counter = ft_wcounter(s, c);
	split = ft_calloc(sizeof (char *), word_counter + 1);
	if (split == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			split[j] = ft_substr(s, i, ft_len(s + i, c));
			j++;
			i = i + ft_len(s + i, c);
		}
	}
	return (split);
}
