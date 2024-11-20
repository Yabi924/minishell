/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:50:46 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/08 18:11:31 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int i)
{
	int	len;

	len = 0;
	if (i == 0)
		len++;
	while (i)
	{
		i /= 16;
		len++;
	}
	return (len);
}

static void	put_hex(unsigned int i, const char c)
{
	char	*lower_hex;
	char	*upper_hex;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (i >= 16)
		put_hex(i / 16, c);
	if (c == 'x')
		write(1, &lower_hex[i % 16], 1);
	else
		write(1, &upper_hex[i % 16], 1);
}

int	printhex(unsigned int i, const char c)
{
	put_hex(i, c);
	return (count_hex(i));
}
