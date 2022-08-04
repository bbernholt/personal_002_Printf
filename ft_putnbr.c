/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:52:05 by bbernhol          #+#    #+#             */
/*   Updated: 2022/07/26 20:05:28 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursiv_print(int input);
static int	is_biggest_negativ(int input);

int	ft_putnbr(int n)
{
	int		return_value;
	char	buffer;

	return_value = 0;
	if (n == -2147483648)
		return_value = is_biggest_negativ(11);
	else
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n = n * -1;
			return_value++;
		}
		if (n <= 9)
		{
			buffer = n + '0';
			write (1, &buffer, 1);
			return_value++;
		}
		else
			return_value += recursiv_print(n);
	}
	return (return_value);
}

static int	recursiv_print(int input)
{
	char	buffer;
	int		return_value;

	return_value = 0;
	if (input != 0)
	{
		return_value++;
		return_value += recursiv_print(input / 10);
		buffer = input % 10 + '0';
		write (1, &buffer, 1);
	}
	return (return_value);
}

static int	is_biggest_negativ(int input)
{
	int	return_value;

	return_value = 11;
	write (1, "-2147483648", 11);
	return (return_value);
}
