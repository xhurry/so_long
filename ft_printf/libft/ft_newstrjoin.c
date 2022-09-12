/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:22:06 by alexamar          #+#    #+#             */
/*   Updated: 2022/09/05 15:22:30 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstrjoin(char *s1, char *s2)
{
	char	*s_join;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	s_join = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s_join == 0)
		return (0);
	while (s1[++i] != '\0')
		s_join[i] = s1[i];
	while (*s2)
		s_join[i++] = *s2++;
	s_join[i] = '\0';
	free(s1);
	return (s_join);
}
