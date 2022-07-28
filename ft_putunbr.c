/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:00:46 by bbernhol          #+#    #+#             */
/*   Updated: 2022/07/28 22:27:12 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putunbr(unsigned int n)
{
    unsigned int biggest_value;
    int buffer;
    
    biggest_value = 4294967295;
    if (n < 0)
        n = biggest_value + n + 1;
    if (n == 0)
        write (1, "0", 1);
    if (n > 0)
    {
        buffer = n % 10 + '0';
        n /= 10;
        if (n != 0)
          ft_putunbr(n);
        write(1, &buffer, 1);
    }
}