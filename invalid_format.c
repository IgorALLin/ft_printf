/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:01:53 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:11:46 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_width(t_strc *st)
{
	while (st->flg[5]-- != 1)
		st->data = ft_add_char_first(st->data, ' ');
}

void	ft_zero(t_strc *st)
{
	while (st->flg[5]-- != 1)
		st->data = ft_add_char_first(st->data, '0');
}

void	ft_minus(t_strc *st)
{
	while (st->flg[5]-- != 1)
		st->data = ft_add_char(st->data, ' ');
}

int		ft_invalid_format(t_strc *st)
{
	int	i;

	i = 0;
	if (st->flg[5] != 0)
	{
		if (st->flg[0] != 0)
			ft_minus(st);
		else if (st->flg[4] != 0)
			ft_zero(st);
		else
			ft_width(st);
	}
	return (ft_strlen(st->data) - 1);
}
