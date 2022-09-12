/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:58:15 by alexamar          #+#    #+#             */
/*   Updated: 2022/02/02 20:51:33 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	l_src;
	size_t	i;

	l_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (l_src);
	while (i < dstsize - 1 && src[i])
	{
		dst [i] = src [i];
		i++;
	}
	dst [i] = '\0';
	return (l_src);
}
