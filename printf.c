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

int	ft_printf(const char *str, ...);
static void ft_matches(const char *str, va_list my_args);

int main(void)
{
	// c s p d i u x X %
    char c = 'A';
    char *s = "String";
    void *p = &c;
    int d = 9000;
    int i = 4500;
    unsigned int u = 3457457;
    int x = 1234;
    int X = 5678;
    printf("Origninal: \n c: %c, \n s: %s, \n p: %p, \n d: %d, \n i: %i, \n u: %u, \n x: %x, \n X: %X \n", c, s, p, d, i, u, x, X);
    ft_printf("My: \n c: %c, \n s: %s, \n p: %p, \n d: %d, \n i: %i, \n u: %u, \n x: %x, \n X: %X \n", c, s, p, d, i, u, x, X);
}

int	ft_printf(const char *str, ...)
{
	int cnt;
	va_list my_args;
	
	va_start(my_args, str);
	cnt = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			cnt++;
			str++;
			ft_matches(str, my_args);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			cnt++;
			str++;
		}
	}
	va_end(my_args);
	return (cnt);
}

static void ft_matches(const char *str, va_list my_args)
{
	//c
	if (*str == 'c')
	{
        
		ft_putchar_fd(va_arg(my_args, int), 1);
        
	}

	//s -> Prints a string (as defined by the common C convention).
	if (*str == 's')
	{
		ft_putstr_fd(va_arg(my_args, char*), 1);
        
	}

	//p -> The void * pointer argument has to be printed in hexadecimal format.
    if (*str == 'p')
	{
        
		ft_itoh(va_arg(my_args, unsigned long), 'a', 1);
        
    }

	//d -> Prints a decimal (base 10) number.
	if (*str == 'd')
	{
        
		ft_putnbr_fd(va_arg(my_args, int), 1);
        
	}
	
	//i -> Prints an integer in base 10.
	if (*str == 'i')
	{
		
        ft_putnbr_fd(va_arg(my_args, int), 1);
        
    }

	//u -> Prints an unsigned decimal (base 10) number.
    if (*str == 'u')
	{
        
		ft_putunbr(va_arg(my_args, unsigned int));
        
	}

	//x -> Prints a number in hexadecimal (base 16) lowercase format.
    if (*str == 'x')
	{
        
		ft_itoh(va_arg(my_args, unsigned int), 'a', 0);
        
    }

	//X -> Prints a number in hexadecimal (base 16) uppercase format.
    if (*str == 'X')
	{
        
		ft_itoh(va_arg(my_args, unsigned int), 'A', 0);
        
    }

	//% -> Prints a percent sign.
	if (*str == '%')
	{
        
		ft_putchar_fd('%', 1);
    }
}