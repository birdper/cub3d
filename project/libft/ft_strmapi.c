/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:45:07 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/19 21:08:39 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char		*new;
	size_t		lensrc;
	size_t		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	lensrc = ft_strlen((char *)src);
	if ((new = (char *)malloc((lensrc + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (i < lensrc)
	{
		new[i] = (*f)(i, src[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
