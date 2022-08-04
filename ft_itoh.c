/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:50:49 by bbernhol          #+#    #+#             */
/*   Updated: 2022/07/28 20:50:49 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static int	ft_is_pointer(uint64_t input, char upper_or_lower, int p_or_not);

int	ft_itoh(uint64_t input, char upper_or_lower, int p_or_not)
{
	int			cnt;
	uint64_t	reminder;

	cnt = 0;
	cnt += ft_is_pointer(input, upper_or_lower, p_or_not);
	if (input < 10 && (input || !p_or_not))
		cnt += ft_putnbr(input);
	else if (input || !p_or_not)
	{
		if (input < 16)
			cnt += ft_putchar((input % 10) + upper_or_lower);
		else
		{
			reminder = input % 16;
			input = input / 16;
			cnt += ft_itoh(input, upper_or_lower, 0);
			if (reminder < 10)
				cnt += ft_putnbr(reminder);
			else
				cnt += ft_putchar((reminder % 10) + upper_or_lower);
		}
	}
	return (cnt);
}

static int	ft_is_pointer(uint64_t input, char upper_or_lower, int p_or_not)
{
	int	cnt;

	cnt = 0;
	if (!input && p_or_not)
	{
		write(1, "(nil)", 5);
		cnt += 5;
	}
	else if (p_or_not)
	{
		write(1, "0x", 2);
		cnt += 2;
	}
	return (cnt);
}
