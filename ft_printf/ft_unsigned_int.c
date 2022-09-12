/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:23:09 by alexamar          #+#    #+#             */
/*   Updated: 2022/06/03 03:48:30 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_int(unsigned int nbr, int*i)
{
	if (nbr < 10)
		ft_char(nbr + '0', i);
	else
	{
		ft_unsigned_int(nbr / 10, i);
		ft_unsigned_int(nbr % 10, i);
	}
}
