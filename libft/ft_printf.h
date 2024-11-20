/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:49:13 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/08/08 18:09:41 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	printc(int c);
int	printp(void *ptr);
int	prints(char *s);
int	printd(int d);
int	printi( int i);
int	printu(unsigned int i);
int	printhex(unsigned int i, const char c);

#endif
