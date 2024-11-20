/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:30:33 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 13:34:19 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		ilen;
	char	*str;
	long	i;

	ilen = intlen(n);
	str = (char *)malloc(sizeof(char) * ilen + 1);
	if (!str)
		return (NULL);
	i = n;
	if (i < 0)
		i = i * -1;
	str[ilen] = '\0';
	while (--ilen >= 0)
	{
		str[ilen] = (i % 10) + '0';
		i = i / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int main()
{
    int nums[] = {0, 9, -9, 10, -10, 8124,
	-9874, 543000, -2147483648LL, 2147483647};
    size_t len = sizeof(nums) / sizeof(nums[0]);
    for (size_t i = 0; i < len; i++)
    {
        char *result = ft_itoa(nums[i]);
        if (result)
        {
            printf("The result of ft_itoa(%ad) is: %s\n", nums[i], result);
            free(result);
        }
    }
    return 0;
}
*/
