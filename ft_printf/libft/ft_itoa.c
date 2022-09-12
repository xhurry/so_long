/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:35:08 by alexamar          #+#    #+#             */
/*   Updated: 2022/02/14 18:41:14 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(long int n, int len, int sign, char *str)
{
	str[len] = '\0';
	if (sign == 1)
	{
		str[0] = '-';
		while (len > 1)
		{
			str[len - 1] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			str[len - 1] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	return (str);
}

static size_t	ft_nlen(int aux)
{
	int	len;

	len = 0;
	if (aux == 0)
	{
		len = 1;
		return (len);
	}
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = n * (-1);
	}
	len = ft_nlen(n);
	str = malloc((sizeof (char)) * (len + sign + 1));
	if (str == NULL)
		return (NULL);
	return (ft_converter(n, (len + sign), sign, str));
}
