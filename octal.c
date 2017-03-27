/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:28:12 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:12:18 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_unsigned_short_oct(va_list argcs, t_strc *st)
{
	unsigned short int	num;

	num = (unsigned short int)va_arg(argcs, unsigned int);
	st->data = ft_itoa_base_ull((unsigned long long)num, 8);
}

void	ft_unsigned_char_oct(va_list argcs, t_strc *st)
{
	unsigned char c;

	c = (unsigned char)va_arg(argcs, unsigned int);
	st->data = ft_itoa_base_ull((unsigned long long)c, 8);
}

void	ft_octal(va_list argcs, t_strc *st)
{
	if (st->spf == 'O')
		st->data = ft_itoa_base_ull(va_arg(argcs, unsigned long long), 8);
	else if (st->lenght[6] != 0)
		st->data = ft_itoa_base_ull((unsigned long long)
				va_arg(argcs, ptrdiff_t), 8);
	else if (st->lenght[5] != 0)
		st->data = ft_itoa_base_ull((unsigned long long)
				va_arg(argcs, size_t), 8);
	else if (st->lenght[4] != 0)
		st->data = ft_itoa_base_ull((unsigned long long)
				va_arg(argcs, uintmax_t), 8);
	else if (st->lenght[3] != 0)
		st->data = ft_itoa_base_ull(va_arg(argcs, unsigned long long), 8);
	else if (st->lenght[2] != 0)
		ft_unsigned_short_oct(argcs, st);
	else if (st->lenght[1] != 0)
		ft_unsigned_char_oct(argcs, st);
	else if (st->lenght[0] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, unsigned long), 8);
	else
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, unsigned int), 8);
	if (st->x0 == 1 && ft_strlen(st->data) == 1 && st->data[0] == '0')
		st->data = ft_strnew(1);
	if (st->flg[3] != 0 && st->data[0] != '0')
		st->data = ft_add_char_first(st->data, '0');
}
