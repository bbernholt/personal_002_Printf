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
#include <stdio.h>

int	ft_printf(const char *str, ...);
static void ft_matches(const char *str, va_list args);

int main(void)
{
	int x = 5;
	int return_value = 0;
	char c = 's';
	return_value = ft_printf("Hier %d ist %c Text \n", x, c);
	printf("Rückgabe MEINS: %d \n", return_value);
	return_value = printf("Hier %d ist %c Text \n", x, c);
	printf("Rückgabe ORIGI: %d \n", return_value);
}

int	ft_printf(const char *str, ...)
{
	int cnt;
	va_list args;
	
	va_start(args, str);
	cnt = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			cnt++;
			str++;
			ft_matches(str, args);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			cnt++;
			str++;
		}
	}
	va_end(args);
	return (cnt);
}

static void ft_matches(const char *str, va_list args)
{
	//c
	if (*str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}

	//s -> Prints a string (as defined by the common C convention).
	if (*str == 'i')
	{
		ft_putstr_fd(va_arg(args, char *s), 1);
	}

	//p -> The void * pointer argument has to be printed in hexadecimal format.

	//d -> Prints a decimal (base 10) number.
	if (*str == 'd')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
	}
	
	//i -> Prints an integer in base 10.
	if (*str == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
	}

	//u -> Prints an unsigned decimal (base 10) number.

	//x -> Prints a number in hexadecimal (base 16) lowercase format.

	//X -> Prints a number in hexadecimal (base 16) uppercase format.

	//% -> Prints a percent sign.
	if (*str == '%')
	{
		ft_putchar_fd('%', 1);
	}
}