/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:22:44 by bbernhol          #+#    #+#             */
/*   Updated: 2022/07/26 20:25:43 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_itoh(uint64_t input, char upper_or_lower, int p_or_not);
int		ft_putunbr(unsigned int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);

#endif // PRINTF_H