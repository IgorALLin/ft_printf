/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:21:13 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:57:21 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_minus_plus_width(t_strc *st)
{
	int	digit;
	int	num;
	int	size;

	if (st->data[0] == '+')
		digit = 1;
	else
		digit = 0;
	num = ft_atoi(st->data);
	if (num < 0)
		num = -num;
	st->data = ft_itoa(num);
	size = st->flg[5] - (ft_strlen(st->data) + 1);
	while (size > 0)
	{
		st->data = ft_add_char_first(st->data, '0');
		size--;
	}
	if (digit == 1)
		st->data = ft_add_char_first(st->data, '+');
	else
		st->data = ft_add_char_first(st->data, '-');
}

void	ft_zero_valid(t_strc *st)
{
	int		size;

	size = ft_strlen(st->data);
	if ((st->data[0] == '+' || st->data[0] == '-') && size < st->flg[5])
	{
		ft_minus_plus_width(st);
		return ;
	}
	if (st->flg[5] > size)
		ft_fun3(st, size);
	if (st->flg[2] != 0)
		st->data[0] = ' ';
}

void	ft_minus_valid(t_strc *st)
{
	int		size;

	size = ft_strlen(st->data);
	if (st->flg[5] > size)
	{
		size = st->flg[5] - size;
		while (size != 0)
		{
			st->data = ft_add_char(st->data, ' ');
			size--;
		}
	}
}

void	ft_width_only(t_strc *st)
{
	int		size;

	size = ft_strlen(st->data);
	if (st->flg[5] > size)
	{
		size = st->flg[5] - size;
		while (size != 0)
		{
			st->data = ft_add_char_first(st->data, ' ');
			size--;
		}
	}
}

void	ft_width_valid(t_strc *st)
{
	if (st->flg[0] != 0)
		ft_minus_valid(st);
	else if (st->flg[4] != 0 && st->flg[6] == 0 &&
			(st->pr != 1 || (st->spf == 'S' || st->spf == 's')))
		ft_zero_valid(st);
	else
		ft_width_only(st);
}
