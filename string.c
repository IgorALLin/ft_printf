/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:15:52 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:13:37 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_null(t_strc *st)
{
	st->data = ft_strnew(7);
	st->data[0] = '(';
	st->data[1] = 'n';
	st->data[2] = 'u';
	st->data[3] = 'l';
	st->data[4] = 'l';
	st->data[5] = ')';
}

void	ft_wide_string(va_list argcs, t_strc *st)
{
	int	*string;
	int	i;

	i = 0;
	string = va_arg(argcs, int*);
	if (string == NULL)
	{
		ft_null(st);
		return ;
	}
	while (string[i])
	{
		ft_wide_char(string[i], st);
		i++;
	}
}

void	ft_string(va_list argcs, t_strc *st)
{
	if (st->spf == 's' && st->lenght[0] == 0)
	{
		st->data = va_arg(argcs, char*);
		if (st->data == NULL)
			ft_null(st);
	}
	else
		ft_wide_string(argcs, st);
	if (st->flg[6] == 0 && st->pr == 1)
		st->data = ft_strnew(1);
	if (st->flg[6] != 0 && st->flg[6] < (int)ft_strlen(st->data))
		st->data = ft_strncpy(ft_strnew(st->flg[6] + 1), st->data, st->flg[6]);
}
