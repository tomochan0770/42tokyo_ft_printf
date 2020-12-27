/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skurosu <skurosu@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:50:04 by skurosu           #+#    #+#             */
/*   Updated: 2020/12/26 03:28:58 by skurosu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*format_num(int n, t_info inf)
{
	char	*ret;
	char	*zeros;
	char	*tmp;
	int		len;
	int		i;

	if (inf.dot && inf.precision == 0 && n == 0)
		return (ft_strdup(""));
	if (!inf.dot || inf.precision < (n < 0 ? digits(-n) + 1 : digits(n)))
		return (ft_itoa(n));
	len = (n < 0 ? inf.precision - digits(-n) + 1 : inf.precision - digits(n));
	zeros = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		if (i == 0 && n < 0)
			zeros[i] = '-';
		else
			zeros[i] = '0';
		i++;
	}
	zeros[i] = '\0';
	tmp = (n < 0 ? ft_itoa_us(-n) : ft_itoa_us(n));
	ret = ft_strjoin(zeros, tmp);
	return (freeturn(&zeros, &tmp, ret));
}

static int	ft_putint_width(int n, t_info info, char *num_str)
{
	int len;
	int digit;

	digit = ft_strlen(num_str);
	len = 0;
	if (info.zero && !info.dot)
	{
		len += (n < 0 ? ft_putchar(*num_str) : 0);
		while (len < info.width - digit + (n < 0 ? 1 : 0))
			len += ft_putchar('0');
		len += ft_putstr(num_str + (n < 0 ? 1 : 0));
	}
	else
	{
		len += (info.minus ? ft_putstr(num_str) : 0);
		while (len < (info.minus ? info.width : info.width - digit))
			len += ft_putchar(' ');
		len += (info.minus ? 0 : ft_putstr(num_str));
	}
	return (len);
}

int			ft_putint_info(int n, t_info info)
{
	int		len;
	char	*num_str;

	if (!(num_str = format_num(n, info)))
		return (-1);
	len = 0;
	if (info.width >= 0)
		len += ft_putint_width(n, info, num_str);
	else
		len += ft_putstr(num_str);
	free(num_str);
	return (len);
}
