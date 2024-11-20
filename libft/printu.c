/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:51:02 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/08 18:06:13 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	countdigit(unsigned int i)
{
	unsigned int	len;

	len = 0;
	if (i == 0)
		len++;
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static void	putint(unsigned int i)
{
	char	*digit;

	digit = "0123456789";
	if (i >= 10)
		putint(i / 10);
	write(1, &digit[i % 10], 1);
}

int	printu(unsigned int i)
{
	putint(i);
	return (countdigit(i));
}
