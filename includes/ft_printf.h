/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:16:05 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/27 15:04:58 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ULL	unsigned long long
# define UL		unsigned long

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

typedef struct	s_strc
{
	int			flg[7];
	int			lenght[7];
	char		spf;
	char		*data;
	char		*format;
	char		x0;
	int			pr;
}				t_strc;

void			ft_fun5(t_strc *st);
int				ft_fun4(t_strc *st, const char *format, int i, int error);
void			ft_fun3(t_strc *st, int size);
void			ft_fun2(t_strc *st);
int				ft_fun1(t_strc *st);
void			ft_precision(t_strc *st);
void			ft_wide_char(int num, t_strc *st);
int				ft_printf(const char *format, ...);
char			*ft_add_char(char *str, char ch);
int				ft_check_format(char ch);
int				ft_read_format(va_list argcs, t_strc *st);
int				ft_add_flags(t_strc *st, int i);
int				ft_add_precision(t_strc *st, int i);
int				ft_add_width(t_strc *st, int i);
int				ft_add_long(t_strc *st, int i);
int				ft_add_h(t_strc *st, int i);
int				ft_invalid_format(t_strc *st);
void			ft_int(va_list argcs, t_strc *st);
int				ft_valid_format(va_list argcs, t_strc *st);
char			*ft_itoa_base_ll(long long int value, int base);
void			ft_width_valid(t_strc *st);
char			*ft_add_char_first(char *str, char ch);
char			*ft_itoa_base_ull(unsigned long long int value, int base);
void			ft_unsigned(va_list argcs, t_strc *st);
char			*ft_itoa_base_ull_lower(unsigned long long int value, int base);
void			ft_hex(va_list argcs, t_strc *st);
void			ft_octal(va_list argcs, t_strc *st);
void			ft_char(va_list argcs, t_strc *st);
void			ft_string(va_list argcs, t_strc *st);
void			ft_pointer(va_list argcs, t_strc *st);
char			*ft_add_char_hex(char *str, char ch);
void			ft_add_wide_s(wchar_t ch, t_strc *st);
void			ft_wide_string(va_list argcs, t_strc *st);

#endif
