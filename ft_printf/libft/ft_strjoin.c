/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:05:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/02 21:46:05 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s_join;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s_join = (char *)malloc ((s1_len + s2_len + 1) * sizeof(char));
	while (*s1)
		s_join[i++] = *s1++;
	while (*s2)
		s_join[i++] = *s2++;
	s_join[i] = '\0';
	return (s_join);
}
