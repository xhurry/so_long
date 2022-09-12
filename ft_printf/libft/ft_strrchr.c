/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:30:38 by alexamar          #+#    #+#             */
/*   Updated: 2022/02/02 21:31:07 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	lenght;

	lenght = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + lenght));
	while (lenght > 0)
	{
		lenght--;
		if (*(s + lenght) == (unsigned char)c)
			return ((char *)(s + lenght));
	}
	return (NULL);
}
