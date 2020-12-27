/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skurosu <skurosu@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:55:28 by skurosu           #+#    #+#             */
/*   Updated: 2020/12/26 01:57:59 by skurosu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*format_str(char *str, t_info info)
{
	int prec;

	prec = info.precision;
	if (!str)
		return (info.dot ? ft_strndup("(null)", prec) : ft_strdup("(null)"));
	else if (prec < 0)
		return (ft_strdup(str));
	else
		return (info.dot ? ft_strndup(str, prec) : ft_strdup(str));
}

int			ft_putstr_info(char *src, t_info info)
{
	char	*str;
	int		len;

	if (!(str = format_str(src, info)))
		return (-1);
	len = 0;
	if (info.width >= 0)
	{
		len += (info.minus ? ft_putstr(str) : 0);
		while (len < (info.minus ? info.width : info.width - ft_strlen(str)))
			len += (info.zero ? ft_putchar('0') : ft_putchar(' '));
		len += (info.minus ? 0 : ft_putstr(str));
	}
	else
		len += ft_putstr(str);
	free(str);
	return (len);
}
