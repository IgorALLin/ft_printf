/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:53:30 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/22 21:58:33 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_check_format(char ch)
{
	if (ch == '0')
		return (0);
	if (ch == 's' || ch == 'S' || ch == 'p' || ch == 'd' || ch == 'D' ||
		ch == 'i' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' ||
		ch == 'x' || ch == 'X' || ch == 'c' || ch == 'C')
		return (1);
	if (ch == '#' || ch == '0' || ch == '-' || ch == '+' || ch == ' ' ||
		ch == '.' || (ch >= '0' && ch <= '9'))
		return (0);
	if (ch == 'h' || ch == 'l' || ch == 'j' || ch == 'z' || ch == 't')
		return (2);
	return (-1);
}
