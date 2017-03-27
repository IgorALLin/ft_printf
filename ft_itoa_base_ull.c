/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:19:19 by exam              #+#    #+#             */
/*   Updated: 2017/03/06 18:13:55 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	ft_un_len(unsigned long long int value, int base)
{
	long int	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base_ull(unsigned long long int value, int base)
{
	unsigned long long int	len;
	char					*str;
	unsigned long long int	i;
	unsigned long long int	res;
	unsigned long long int	nb;

	nb = value;
	i = 0;
	len = ft_un_len(nb, base);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len > i)
	{
		len--;
		res = nb % base;
		if (res < 10)
			str[len] = res + '0';
		else
			str[len] = res + 'A' - 10;
		nb = nb / base;
	}
	return (str);
}
