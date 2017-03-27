/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:25:01 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:14:01 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_unsigned_short(va_list argcs, t_strc *st)
{
	unsigned short int	num;

	num = (unsigned short int)va_arg(argcs, unsigned int);
	st->data = ft_itoa_base_ull((unsigned long long)num, 10);
}

void	ft_unsigned_char(va_list argcs, t_strc *st)
{
	unsigned char c;

	c = (unsigned char)va_arg(argcs, unsigned int);
	st->data = ft_itoa_base_ull((unsigned long long)c, 10);
}

void	ft_unsigned(va_list argcs, t_strc *st)
{
	if (st->spf == 'U')
		st->data = ft_itoa_base_ull(va_arg(argcs, ULL), 10);
	else if (st->lenght[6] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, ptrdiff_t), 10);
	else if (st->lenght[5] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, size_t), 10);
	else if (st->lenght[4] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, uintmax_t), 10);
	else if (st->lenght[3] != 0)
		st->data = ft_itoa_base_ull(va_arg(argcs, ULL), 10);
	else if (st->lenght[2] != 0)
		ft_unsigned_short(argcs, st);
	else if (st->lenght[1] != 0)
		ft_unsigned_char(argcs, st);
	else if (st->lenght[0] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, unsigned long), 10);
	else
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, unsigned int), 10);
	if (st->x0 == 1 && ft_strlen(st->data) == 1 && st->data[0] == '0')
		st->data = ft_strnew(1);
}
