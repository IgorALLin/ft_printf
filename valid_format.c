/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:33:11 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 16:03:47 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_minus_plus(t_strc *st)
{
	int	num;
	int	size;
	int digit;

	if (st->data[0] == '+')
		digit = 1;
	else
		digit = 0;
	num = ft_atoi(st->data);
	num = -num;
	st->data = ft_itoa(num);
	size = st->flg[6] - ft_strlen(st->data);
	while (size > 0)
	{
		st->data = ft_add_char_first(st->data, '0');
		size--;
	}
	if (digit == 0)
		st->data = ft_add_char_first(st->data, '-');
	else
		st->data = ft_add_char_first(st->data, '+');
}

void	ft_precision(t_strc *st)
{
	int	size;

	if (st->spf == 'c' || st->spf == 'C' || st->spf == 's' || st->spf == 'S'
			|| st->spf == 'p')
		return ;
	if (st->data[0] == '-' || st->data[0] == '+')
	{
		ft_minus_plus(st);
		return ;
	}
	size = st->flg[6] - ft_strlen(st->data);
	if (size > 0)
	{
		while (size != 0)
		{
			st->data = ft_add_char_first(st->data, '0');
			size--;
		}
	}
	if (st->flg[2] != 0 && st->flg[5] <= (int)ft_strlen(st->data))
		st->data = ft_add_char_first(st->data, ' ');
}

void	ft_plus(t_strc *st)
{
	if (st->spf == 'c' || st->spf == 'C' || st->spf == 's' || st->spf == 'S'
		|| st->spf == 'u' || st->spf == 'U' || st->spf == 'x' ||
		st->spf == 'X' || st->spf == 'o' || st->spf == 'O' || st->spf == 'p')
		return ;
	if (st->flg[2] != 0 && st->flg[1] == 0 && (ft_atoi(st->data) > -1) &&
		(st->flg[5] == 0 || st->flg[0] != 0))
		st->data = ft_add_char_first(st->data, ' ');
	else if (st->flg[1] != 0 && ft_atoi(st->data) > -1)
		st->data = ft_add_char_first(st->data, '+');
}

int		ft_valid_flags(t_strc *st)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (st->flg[6] != 0)
		ft_precision(st);
	if (st->flg[1] != 0 || st->flg[2] != 0)
		ft_plus(st);
	if (st->flg[5] != 0)
		ft_width_valid(st);
	len = ft_strlen(st->data);
	return (len);
}

int		ft_valid_format(va_list argcs, t_strc *st)
{
	int		len;

	if (st->spf == 'd' || st->spf == 'D' || st->spf == 'i')
		ft_int(argcs, st);
	if (st->spf == 'u' || st->spf == 'U')
		ft_unsigned(argcs, st);
	if (st->spf == 'x' || st->spf == 'X')
		ft_hex(argcs, st);
	if (st->spf == 'o' || st->spf == 'O')
		ft_octal(argcs, st);
	if (st->spf == 's' || st->spf == 'S')
		ft_string(argcs, st);
	if (st->spf == 'c' || st->spf == 'C')
		ft_char(argcs, st);
	if (st->spf == 'p')
		ft_pointer(argcs, st);
	len = ft_valid_flags(st);
	if (st->x0 == 1 && (st->spf == 'c' || st->spf == 'C') && st->flg[5] != 0)
		len = ft_fun1(st);
	else if (st->x0 == 1 && (st->spf == 'c' || st->spf == 'C'))
		len++;
	return (len - 1);
}
