/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexamar <xandemvieira@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:30:51 by alexamar          #+#    #+#             */
/*   Updated: 2022/06/06 22:10:45 by alexamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define HEXADECIMAL_U_CASE "0123456789ABCDEF"
# define HEXADECIMAL_L_CASE "0123456789abcdef"

int		ft_printf(const char *format, ...);
void	ft_check_str(const char *str, va_list args, int *i);
void	ft_char(char str, int *i);
void	ft_string(char *str, int *i);
void	ft_pointer(long int ptr, int *i);
void	ft_int(int nbr, int *i);
void	ft_unsigned_int(unsigned int u_nbr, int*i);
void	ft_hexadecimal(unsigned long int n, char char_case, int *i);

#endif