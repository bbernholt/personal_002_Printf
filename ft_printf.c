/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:20:51 by bbernhol          #+#    #+#             */
/*   Updated: 2022/07/26 21:46:16 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

int			ft_printf(const char *str, ...);
static int	ft_matches(const char *str, va_list my_args);

int	ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	my_args;

	va_start(my_args, str);
	cnt = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			cnt += ft_matches(str, my_args);
			str++;
		}
		else
		{
			ft_putchar(*str);
			cnt++;
			str++;
		}
	}
	va_end(my_args);
	return (cnt);
}

static int	ft_matches(const char *str, va_list my_args)
{
	int	cnt;

	cnt = 0;
	if (*str == 'c')
		cnt += ft_putchar(va_arg(my_args, int));
	if (*str == 's')
		cnt += ft_putstr(va_arg(my_args, char *));
	if (*str == 'p')
		cnt += ft_itoh(va_arg(my_args, unsigned long), 'a', 1);
	if (*str == 'd' || *str == 'i')
		cnt += ft_putnbr(va_arg(my_args, int));
	if (*str == 'u')
		cnt += ft_putunbr(va_arg(my_args, unsigned int));
	if (*str == 'x')
		cnt += ft_itoh(va_arg(my_args, unsigned int), 'a', 0);
	if (*str == 'X')
		cnt += ft_itoh(va_arg(my_args, unsigned int), 'A', 0);
	if (*str == '%')
		cnt += ft_putchar('%');
	return (cnt);
}
