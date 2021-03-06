/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:28:29 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/06 17:21:53 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (ft_strlen(src) < len)
	{
		n = ft_strlen(src);
		while (n < len)
		{
			dst[n] = '\0';
			n++;
		}
	}
	while (src[i] != '\0' && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
