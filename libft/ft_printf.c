/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:48:49 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/08 18:09:00 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c %p %s %d %i %u %x %X %%
static int	check(const char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = printc(va_arg(arg, int));
	else if (c == 'p')
		len = printp(va_arg(arg, void *));
	else if (c == 's')
		len = prints(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len = printd(va_arg(arg, int));
	else if (c == 'u')
		len = printu(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len = printhex(va_arg(arg, unsigned int), c);
	else if (c == '%')
	{
		printc('%');
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	tag;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	va_start(tag, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += check(str[i], tag);
		}
		else
			len += printc(str[i]);
		i++;
	}
	va_end(tag);
	return (len);
}
