/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:24:23 by alexamar          #+#    #+#             */
/*   Updated: 2022/06/02 21:10:05 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int(int nbr, int *i)
{
	if (nbr == -2147483648)
	{
		ft_char('-', i);
		ft_char('2', i);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_char('-', i);
		nbr *= -1;
	}
	if (nbr < 10)
		ft_char(nbr + '0', i);
	else
	{
		ft_int(nbr / 10, i);
		ft_int(nbr % 10, i);
	}
}
