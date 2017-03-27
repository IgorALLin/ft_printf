/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:36:27 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:10:27 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_add_precision_p(t_strc *st)
{
	int	size;

	size = st->flg[6] - ft_strlen(st->data);
	while (size > 0)
	{
		st->data = ft_add_char_first(st->data, '0');
		size--;
	}
}

void	ft_pointer(va_list argcs, t_strc *st)
{
	st->data = ft_itoa_base_ull_lower((ULL)va_arg(argcs, void*), 16);
	if (st->x0 == 1 && ft_strlen(st->data) == 1 && st->data[0] == '0')
		st->data = ft_strnew(1);
	if (st->flg[6] != 0)
		ft_add_precision_p(st);
	st->data = ft_add_char_first(st->data, 'x');
	st->data = ft_add_char_first(st->data, '0');
}
