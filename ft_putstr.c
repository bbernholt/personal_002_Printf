/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbernhol <bbernhol@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:23:44 by bbernhol          #+#    #+#             */
/*   Updated: 2022/06/05 21:32:23 by bbernhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		i = 6;
	}
	else
	{	
		while (s[i] != '\0')
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	return (i);
}
