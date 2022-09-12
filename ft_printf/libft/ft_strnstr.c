/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:29:08 by alexamar          #+#    #+#             */
/*   Updated: 2021/11/08 19:31:28 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	h_len;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	h_len = ft_strlen(haystack);
	if (n_len > len)
		return (NULL);
	if (len > h_len)
		len = h_len;
	index = 0;
	while ((haystack + index) <= (haystack + len - n_len))
	{
		if (ft_strncmp((haystack + index), needle, n_len) == 0)
			return ((char *)(haystack + index));
		index++;
	}
	return (NULL);
}
