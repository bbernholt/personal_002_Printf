/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:00:46 by bbernhol          #+#    #+#             */
/*   Updated: 2022/08/04 17:15:51 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_putunbr(unsigned int n)
{
	int	return_value;
	int	buffer;

	return_value = 0;
	if (n < 0)
		n = 4294967295 + n + 1;
	if (n == 0)
	{
		write (1, "0", 1);
		return_value++;
	}
	if (n > 0)
	{
		return_value++;
		buffer = n % 10 + '0';
		n /= 10;
		if (n != 0)
		{
			return_value += ft_putunbr(n);
		}
		write(1, &buffer, 1);
	}
	return (return_value);
}
