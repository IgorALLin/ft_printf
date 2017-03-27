/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:43:47 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:05:50 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_add_lenght(t_strc *st, int i)
{
	if (st->format[i] == 'l')
		i = ft_add_long(st, i);
	if (st->format[i] == 'h')
		i = ft_add_h(st, i);
	if (st->format[i] == 'j')
		st->lenght[4] = 1;
	if (st->format[i] == 'z')
		st->lenght[5] = 1;
	if (st->format[i] == 't')
		st->lenght[6] = 1;
	return (i);
}

int	ft_add_flg(t_strc *st, int i)
{
	if (st->format[i] == '-')
	{
		st->flg[4] = 0;
		st->flg[0] = 1;
	}
	else if (st->format[i] == '+')
	{
		st->flg[2] = 0;
		st->flg[1] = 1;
	}
	else if (st->format[i] == ' ' && st->flg[1] == 0)
		st->flg[2] = 1;
	else if (st->format[i] == '#')
		st->flg[3] = 1;
	else if (st->format[i] == '0' && st->flg[0] == 0)
		st->flg[4] = 1;
	else if (st->format[i] == '.')
	{
		st->pr = 1;
		i = ft_add_precision(st, i);
	}
	else if (st->format[i] >= '1' && st->format[i] <= '9')
		i = ft_add_width(st, i);
	return (i);
}

int	ft_add_flags(t_strc *st, int i)
{
	if (ft_check_format(st->format[i]) == 0)
		i = ft_add_flg(st, i);
	else
		i = ft_add_lenght(st, i);
	return (i);
}
