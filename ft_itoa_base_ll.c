/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:19:19 by exam              #+#    #+#             */
/*   Updated: 2017/03/22 22:10:37 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	ft_n_len(long long int value, int base)
{
	long long int	len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		value = -value;
		if (base == 10)
			len++;
	}
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char		*ft_res(long long int len, long long int i,
					long long int value, long long int base)
{
	char	*ret;
	int		res;

	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (i > 0)
		ret[0] = '-';
	while (len > i)
	{
		len--;
		res = value % base;
		if (res < 10)
			ret[len] = res + '0';
		else
			ret[len] = res + 'A' - 10;
		value = value / base;
	}
	return (ret);
}

char		*ft_min(void)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * 21);
	ret = "-9223372036854775808";
	return (ret);
}

char		*ft_itoa_base_ll(long long int value, int base)
{
	long long int	len;
	char			*str;
	long long int	i;

	if (value < -9223372036854775807)
	{
		str = ft_min();
		return (str);
	}
	i = 0;
	len = ft_n_len(value, base);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (value < 0)
	{
		value = -value;
		if (base == 10)
		{
			str[0] = '-';
			i++;
		}
	}
	str = ft_res(len, i, value, base);
	return (str);
}
