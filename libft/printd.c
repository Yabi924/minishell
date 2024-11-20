/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:50:33 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/08 18:10:21 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countdigit(int d)
{
	int	len;

	len = 0;
	if (d <= 0)
		len++;
	while (d)
	{
		d = d / 10;
		len++;
	}
	return (len);
}

static void	putint(int d)
{
	char	*digit;

	digit = "0123456789";
	if (d >= 10)
		putint(d / 10);
	write (1, &digit[d % 10], 1);
}

int	printd(int d)
{
	int	len;

	len = countdigit(d);
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (len);
	}
	if (d < 0)
	{
		d *= -1;
		write (1, "-", 1);
	}
	putint(d);
	return (len);
}
