/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:11:42 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 16:00:01 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_check_error(t_strc *st)
{
	int	i;

	i = 0;
	while (st->format[i])
	{
		if (ft_check_format(st->format[i]) == -1)
		{
			while (st->format[i])
			{
				st->data = ft_add_char(st->data, st->format[i]);
				i++;
			}
			return (-1);
		}
		i = ft_add_flags(st, i);
		i++;
	}
	return (0);
}

int	ft_read_format(va_list argcs, t_strc *st)
{
	int	len;

	if (st->data[0] == '%')
		len = 0;
	else if (ft_check_error(st) == -1)
		len = ft_invalid_format(st);
	else
		len = ft_valid_format(argcs, st);
	return (len);
}
