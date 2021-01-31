/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:55:38 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/20 16:04:53 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_countlines(const char *src, char c)
{
	size_t			countlines;

	countlines = 0;
	while (*src != 0)
	{
		if (*src != c && (*(src + 1) == c || *(src + 1) == '\0'))
			countlines++;
		src++;
	}
	return (countlines);
}

static char			**ft_init_arr(const char *src, char c)
{
	size_t			countlines;
	char			**arr;

	if (src == NULL)
		return (NULL);
	countlines = ft_get_countlines(src, c);
	if ((arr = (char **)malloc((countlines + 1) * sizeof(char *))) == NULL)
		return (NULL);
	return (arr);
}

static void			ft_cleanup(char **arr)
{
	size_t			i;

	i = 0;
	while (arr[i] != NULL)
		free(&arr[i++]);
	free(arr);
}

char				**ft_split(const char *src, char c)
{
	char			**arr;
	const char		*start;
	const char		*r_del;
	size_t			i;

	if ((arr = ft_init_arr(src, c)) == NULL)
		return (NULL);
	i = 0;
	while (*src != 0)
	{
		while (*src == c && *src != '\0')
			src++;
		start = src;
		while (*src != c && *src != '\0')
			src++;
		r_del = src;
		if ((r_del - start) != 0)
			if ((arr[i++] = ft_substr(start, 0, r_del - start)) == NULL)
			{
				ft_cleanup(arr);
				return (NULL);
			}
	}
	arr[i] = NULL;
	return (arr);
}
