/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:55:52 by alexamar          #+#    #+#             */
/*   Updated: 2022/06/03 16:08:23 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(long int ptr, int *i)
{
	if (ptr)
	{
		write(1, "0x", 2);
		*i += 2;
		ft_hexadecimal(ptr, 'x', i);
	}
	else
	{
		write (1, "(nil)", 5);
		*i += 5;
	}
}
