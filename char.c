/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:32:17 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 16:27:44 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_wide_char1(int num, t_strc *st)
{
	unsigned char	res[4];

	res[0] = (num >> 12) + 224;
	res[1] = num >> 6;
	res[1] = res[1] << 2;
	res[1] = res[1] >> 2;
	res[1] += 128;
	res[2] = num << 2;
	res[2] = (res[2] >> 2) + 128;
	res[3] = 0;
	if ((st->spf == 's' || st->spf == 'S') && st->flg[6] != 0 &&
		(int)(ft_strlen((char *)res) + ft_strlen(st->data)) > st->flg[6])
		return ;
	st->data = ft_strjoin(st->data, (char*)res);
}

void	ft_wide_char(int num, t_strc *st)
{
	unsigned char	res[3];

	if (num < 128)
		st->data = ft_add_char(st->data, (char)num);
	else if (num < 2048)
	{
		res[0] = (num >> 6) + 192;
		res[1] = num << 2;
		res[1] = (res[1] >> 2) + 128;
		res[2] = 0;
		if ((st->spf == 's' || st->spf == 'S') && st->flg[6] != 0 &&
			(int)(ft_strlen((char *)res) + ft_strlen(st->data)) > st->flg[6])
			return ;
		st->data = ft_strjoin(st->data, (char*)res);
	}
	else if (num > 2048)
		ft_wide_char1(num, st);
}

void	ft_char(va_list argcs, t_strc *st)
{
	int	i;
	int	num;

	if ((st->spf == 'c' && st->lenght[0] == 0) ||
		(st->spf == 'C' && st->lenght[0] == 0))
	{
		st->data = ft_strnew(2);
		i = va_arg(argcs, int);
		st->data[0] = i;
		if (i == 0)
			st->x0 = 1;
	}
	else
	{
		num = va_arg(argcs, int);
		if (num == 0)
		{
			st->x0 = 1;
			return ;
		}
		ft_wide_char(num, st);
	}
}
