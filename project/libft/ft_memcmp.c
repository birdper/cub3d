/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:19:17 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/04 14:55:21 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (*(const char *)s1 != *(const char *)s2)
			return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
