/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:58:39 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:07:06 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_fun5(t_strc *st)
{
	if (st->x0 == 1 && (st->spf == 'c' || st->spf == 'C'))
	{
		ft_putstr(st->data);
		write(1, "\0", 1);
	}
	else
		ft_putstr(st->data);
}

int		ft_fun4(t_strc *st, const char *format, int i, int error)
{
	while (format[i] != '\0')
	{
		if (ft_check_format(format[i]) == -1 && format[i] != '%')
			error = 1;
		if (format[i] == '%' && error == 0)
		{
			st->format = ft_add_char(st->format, format[i]);
			return (i);
		}
		if (format[i] == '%' && error == 1)
			return (i - 1);
		st->format = ft_add_char(st->format, format[i]);
		if (ft_check_format(format[i]) == 1)
		{
			st->spf = format[i];
			return (i);
		}
		if ((error == 1) && ((format[i] >= 'a' && format[i] <= 'z')
			|| (format[i] >= 'A' && format[i] <= 'Z')))
			return (i);
		i++;
	}
	if (error == 0 && ft_check_format(st->spf) != 1)
		st->format = ft_strnew(1);
	return (i - 1);
}

void	ft_fun3(t_strc *st, int size)
{
	size = st->flg[5] - size;
	if (st->spf == 'p' || (st->flg[3] != 0 &&
		(st->spf == 'x' || st->spf == 'X')))
	{
		while (size != 0)
		{
			st->data = ft_add_char_hex(st->data, '0');
			size--;
		}
	}
	else
	{
		while (size != 0)
		{
			st->data = ft_add_char_first(st->data, '0');
			size--;
		}
	}
}

void	ft_fun2(t_strc *st)
{
	if (st->flg[6] != 0)
	{
		ft_precision(st);
		st->flg[6] = 0;
	}
	st->data = ft_add_char_first(st->data, 'x');
	st->data = ft_add_char_first(st->data, '0');
}

int		ft_fun1(t_strc *st)
{
	int	len;

	st->data = ft_strnew(1);
	len = 0;
	while (st->flg[5] != 1)
	{
		if (st->flg[4] == 0)
			st->data = ft_add_char(st->data, ' ');
		else
			st->data = ft_add_char(st->data, '0');
		st->flg[5]--;
		len++;
	}
	len++;
	return (len);
}
