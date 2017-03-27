/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:02:46 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:10:01 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_unsigned_short_hex(va_list argcs, t_strc *st)
{
	unsigned short int	num;

	num = (unsigned short int)va_arg(argcs, unsigned int);
	if (st->spf == 'X')
		st->data = ft_itoa_base_ull((unsigned long long)num, 16);
	else
		st->data = ft_itoa_base_ull_lower((unsigned long long)num, 16);
}

void	ft_unsigned_char_hex(va_list argcs, t_strc *st)
{
	unsigned char c;

	c = (unsigned char)va_arg(argcs, unsigned int);
	if (st->spf == 'X')
		st->data = ft_itoa_base_ull((unsigned long long)c, 16);
	else
		st->data = ft_itoa_base_ull_lower((unsigned long long)c, 16);
}

void	ft_lower(va_list argcs, t_strc *st)
{
	if (st->lenght[6] != 0)
		st->data = ft_itoa_base_ull_lower((ULL)va_arg(argcs, ptrdiff_t), 16);
	else if (st->lenght[5] != 0)
		st->data = ft_itoa_base_ull_lower((ULL)va_arg(argcs, size_t), 16);
	else if (st->lenght[4] != 0)
		st->data = ft_itoa_base_ull_lower((ULL)va_arg(argcs, uintmax_t), 16);
	else if (st->lenght[3] != 0)
		st->data = ft_itoa_base_ull_lower(va_arg(argcs, ULL), 16);
	else if (st->lenght[2] != 0)
		ft_unsigned_short_hex(argcs, st);
	else if (st->lenght[1] != 0)
		ft_unsigned_char_hex(argcs, st);
	else if (st->lenght[0] != 0)
		st->data = ft_itoa_base_ull_lower((ULL)va_arg(argcs, UL), 16);
	else
		st->data = ft_itoa_base_ull_lower((ULL)va_arg(argcs, unsigned int), 16);
	if (st->flg[3] != 0 && st->data[0] != '0')
		ft_fun2(st);
}

void	ft_upper(va_list argcs, t_strc *st)
{
	if (st->lenght[6] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, ptrdiff_t), 16);
	else if (st->lenght[5] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, size_t), 16);
	else if (st->lenght[4] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, uintmax_t), 16);
	else if (st->lenght[3] != 0)
		st->data = ft_itoa_base_ull(va_arg(argcs, ULL), 16);
	else if (st->lenght[2] != 0)
		ft_unsigned_short_hex(argcs, st);
	else if (st->lenght[1] != 0)
		ft_unsigned_char_hex(argcs, st);
	else if (st->lenght[0] != 0)
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, ULL), 16);
	else
		st->data = ft_itoa_base_ull((ULL)va_arg(argcs, unsigned int), 16);
	if (st->flg[3] != 0 && st->data[0] != '0')
	{
		if (st->flg[6] != 0)
			ft_precision(st);
		st->flg[6] = 0;
		st->data = ft_add_char_first(st->data, 'X');
		st->data = ft_add_char_first(st->data, '0');
	}
}

void	ft_hex(va_list argcs, t_strc *st)
{
	if (st->spf == 'X')
		ft_upper(argcs, st);
	else
		ft_lower(argcs, st);
	if (st->x0 == 1 && st->data[0] == '0' && ft_strlen(st->data) == 1)
		st->data = ft_strnew(1);
}
