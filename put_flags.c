/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:10:40 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:27:49 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_add_h(t_strc *st, int i)
{
	if (st->format[i + 1] == 'h' && st->lenght[2] == 0)
	{
		st->lenght[1] = 1;
		return (i + 1);
	}
	else
	{
		st->lenght[2] = 1;
		st->lenght[1] = 0;
	}
	return (i);
}

int	ft_add_long(t_strc *st, int i)
{
	if (st->format[i + 1] == 'l')
	{
		st->lenght[3] = 1;
		st->lenght[0] = 0;
		return (i + 1);
	}
	else if (st->lenght[3] == 0)
		st->lenght[0] = 1;
	return (i);
}

int	ft_add_width(t_strc *st, int i)
{
	char	*num;

	num = ft_strnew(1);
	while (st->format[i] >= '0' && st->format[i] <= '9')
	{
		num = ft_add_char(num, st->format[i]);
		i++;
	}
	st->flg[5] = ft_atoi(num);
	return (i - 1);
}

int	ft_add_precision(t_strc *st, int i)
{
	char	*num;

	num = ft_strnew(1);
	if (st->format[i + 1] >= '1' && st->format[i + 1] <= '9')
	{
		i++;
		while (st->format[i] >= '0' && st->format[i] <= '9')
		{
			num = ft_add_char(num, st->format[i]);
			i++;
		}
		st->flg[6] = ft_atoi(num);
		return (i - 1);
	}
	else
		st->flg[6] = 0;
	if ((st->spf == 'x' || st->spf == 'X' || st->spf == 'o' ||
		st->spf == 'O' || st->spf == 'p' || st->spf == 'u' ||
		st->spf == 'U' || st->spf == 'i' ||
		st->spf == 'd') && st->flg[6] == 0)
		st->x0 = 1;
	if (st->format[i + 1] == '0')
		return (i + 1);
	return (i);
}
