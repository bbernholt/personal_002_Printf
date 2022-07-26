/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:52:05 by bbernhol          #+#    #+#             */
/*   Updated: 2022/07/26 20:05:28 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursiv_print(int input, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int		biggest_negative;
	char	buffer;

	biggest_negative = -2147483648;
	if (n == biggest_negative)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = n * -1;
		}
		if (n <= 9)
		{
			buffer = n + '0';
			write (fd, &buffer, 1);
		}
		else
			recursiv_print(n, fd);
	}
}

static void	recursiv_print(int input, int fd)
{
	char	buffer;

	if (input != 0)
	{
		recursiv_print(input / 10, fd);
		buffer = input % 10 + '0';
		write (fd, &buffer, 1);
	}
}
