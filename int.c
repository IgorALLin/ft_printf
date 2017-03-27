/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:58:17 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:11:09 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_short(va_list argcs, t_strc *st)
{
	short int	num;

	num = (short int)va_arg(argcs, int);
	st->data = ft_itoa_base_ll((long long)num, 10);
}

void		ft_signed_char(va_list argcs, t_strc *st)
{
	signed char	c;

	c = (signed char)va_arg(argcs, int);
	st->data = ft_itoa_base_ll((long long)c, 10);
}

void		ft_int(va_list argcs, t_strc *st)
{
	if (st->spf == 'D')
		st->data = ft_itoa_base_ll(va_arg(argcs, long int), 10);
	else if (st->lenght[6] != 0)
		st->data = ft_itoa_base_ll((long long)va_arg(argcs, ptrdiff_t), 10);
	else if (st->lenght[5] != 0)
		st->data = ft_itoa_base_ll((long long)va_arg(argcs, size_t), 10);
	else if (st->lenght[4] != 0)
		st->data = ft_itoa_base_ll((long long)va_arg(argcs, uintmax_t), 10);
	else if (st->lenght[3] != 0)
		st->data = ft_itoa_base_ll(va_arg(argcs, long long), 10);
	else if (st->lenght[0] != 0)
		st->data = ft_itoa_base_ll((long long)va_arg(argcs, long), 10);
	else if (st->lenght[2] != 0)
		ft_short(argcs, st);
	else if (st->lenght[1] != 0)
		ft_signed_char(argcs, st);
	else
		st->data = ft_itoa_base_ll((long long)va_arg(argcs, int), 10);
	if (st->x0 == 1 && ft_strlen(st->data) == 1 && st->data[0] == '0')
		st->data = ft_strnew(1);
}
