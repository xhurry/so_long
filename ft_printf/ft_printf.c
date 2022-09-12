/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 05:13:43 by alexamar          #+#    #+#             */
/*   Updated: 2022/06/06 22:14:00 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_str(const char *str, va_list args, int *i)
{
	while (*str)
	{
		if (*str != '%')
			ft_char(*str, i);
		else
		{
			str++;
			if (*str == '%')
				ft_char(*str, i);
			if (*str == 'c')
				ft_char(va_arg(args, int), i);
			if (*str == 's')
				ft_string(va_arg(args, char *), i);
			if (*str == 'p')
				ft_pointer(va_arg(args, long int), i);
			if (*str == 'd' || *str == 'i')
				ft_int(va_arg(args, int), i);
			if (*str == 'u')
				ft_unsigned_int(va_arg(args, unsigned int), i);
			if (*str == 'x' || *str == 'X')
				ft_hexadecimal(va_arg(args, unsigned int), *str, i);
		}
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	ft_check_str(str, args, &i);
	va_end(args);
	return (i);
}
