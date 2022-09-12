/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:48:25 by alexamar          #+#    #+#             */
/*   Updated: 2022/06/03 16:18:22 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal(unsigned long int n, char char_case, int *i)
{
	char	hexadecimal[64];
	int		counter;

	counter = 0;
	if (n == 0)
	{
		counter = 1;
		hexadecimal[0] = '0';
	}
	while (n)
	{
		if (char_case == 'x')
			hexadecimal[counter] = HEXADECIMAL_L_CASE[n % 16];
		else
			hexadecimal[counter] = HEXADECIMAL_U_CASE[n % 16];
		n = n / 16;
		counter++;
	}
	*i += counter;
	while (counter)
	{
		write(1, &hexadecimal[counter - 1], 1);
		counter--;
	}
}
