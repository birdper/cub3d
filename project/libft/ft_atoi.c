/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:16:00 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/12 16:37:31 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long		nbr;
	int			sign;
	long		long_max;
	int			d;

	nbr = 0;
	sign = 1;
	while ((*str && 9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	long_max = (long)((unsigned long)~0 >> 1);
	while (ft_isdigit(*str))
	{
		d = *str - '0';
		if (nbr > (long_max - d) / 10)
			return (sign == 1 ? -1 : 0);
		nbr = nbr * 10 + d;
		str++;
	}
	return ((int)nbr * sign);
}
