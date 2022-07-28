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

// void	ft_putchar_fd(char c, int fd)
// {
// 	write (fd, &c, 1);
// }

// static void	recursiv_print(int input, int fd);

// void	ft_putnbr_fd(int n, int fd)
// {
// 	int		biggest_negative;
// 	char	buffer;

// 	biggest_negative = -2147483648;
// 	if (n == biggest_negative)
// 		write (fd, "-2147483648", 11);
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			write (fd, "-", 1);
// 			n = n * -1;
// 		}
// 		if (n <= 9)
// 		{
// 			buffer = n + '0';
// 			write (fd, &buffer, 1);
// 		}
// 		else
// 			recursiv_print(n, fd);
// 	}
// }

// static void	recursiv_print(int input, int fd)
// {
// 	char	buffer;

// 	if (input != 0)
// 	{
// 		recursiv_print(input / 10, fd);
// 		buffer = input % 10 + '0';
// 		write (fd, &buffer, 1);
// 	}
// }

// void ft_itoh(unsigned int input, char upper_or_lower, int p_or_not);

// int main(void)
// {
//     char l = 'A';
//     unsigned int i = 15;    // F
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 10;                 // A
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 44;                 // 2C
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 204;                 // CC
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 50;                 // 32
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 0;                 // 0
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 1;                 // 1
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 242;                 // F2
//     ft_itoh(i, 'A', 0);
//     printf("\n");
//     i = 9000;                 // 9000
//     ft_itoh(i, 'A', 0);
//     printf("\n");

//     void *ptr = &l;
//    printf("orig: ptr at %p\n", ptr);
//    ft_itoh((unsigned int)ptr, 'A', 1);
// }

void ft_itoh(uint64_t input, char upper_or_lower, int p_or_not)
{
    uint64_t reminder;
    
    if (p_or_not)
        write(1,"0x", 2);
    reminder = 0;
    if (input < 10)
        ft_putnbr_fd(input, 1);
    else
    {
        if (input < 16)
            ft_putchar_fd((input % 10) + upper_or_lower, 1);
        else
        {
            reminder = input % 16; // 0
            input = input / 16;
            ft_itoh(input, upper_or_lower, 0);
            if (reminder < 10)
                ft_putnbr_fd(reminder, 1);
            else
                ft_putchar_fd((reminder % 10) + upper_or_lower, 1);
        }
    }
}

// void ft_itoh(unsigned int input, char upper_or_lower)
// {
//     unsigned int reminder;
    
//     reminder = input;
//     if (input < 10)
//        ft_putnbr_fd(input, 1);
//     else
//     {
//         if (input < 16)
//             ft_putchar_fd((reminder % 10) + upper_or_lower, 1);
//         while (input >= 16)
//         {
//             reminder = input % 16; // 0
//             input /= 16;
//             if (input > 0)
//                 ft_itoh(input, upper_or_lower);
//             if (reminder < 10)
//                 ft_putnbr_fd(reminder, 1);
//             else
//                 ft_putchar_fd((reminder % 10) +upper_or_lower, 1);
//         }
//     }
// }