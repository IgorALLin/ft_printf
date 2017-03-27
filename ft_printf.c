/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:39:22 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:05:05 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_free_st(t_strc *st)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		st->flg[i] = 0;
		st->lenght[i] = 0;
		i++;
	}
	st->x0 = 0;
	st->pr = 0;
	st->data = ft_strnew(1);
	st->format = ft_strnew(1);
}

void	ft_new_st(t_strc *st)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		st->flg[i] = 0;
		st->lenght[i] = 0;
		i++;
	}
	st->x0 = 0;
	st->pr = 0;
	st->data = ft_strnew(1);
	st->format = ft_strnew(1);
}

int		ft_add_format(t_strc *st, const char *format, int i)
{
	int	error;

	error = 0;
	if (format[i] == '%')
	{
		st->data = ft_add_char(st->data, format[i]);
		return (i);
	}
	return (ft_fun4(st, format, i, error));
}

int		ft_printf(char const *format, ...)
{
	va_list		argcs;
	t_strc		*st;
	int			len;
	int			i;

	i = 0;
	len = 0;
	va_start(argcs, format);
	st = (t_strc *)malloc(sizeof(t_strc));
	ft_new_st(st);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			i = ft_add_format(st, format, i + 1);
			len = len + ft_read_format(argcs, st);
			ft_fun5(st);
			ft_free_st(st);
		}
		i++;
		len++;
	}
	return (len);
}
