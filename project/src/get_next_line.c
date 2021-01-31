/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:59:02 by nbirdper          #+#    #+#             */
/*   Updated: 2020/12/11 19:00:55 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	static t_list_gnl	*lst_rdrs;
	t_list_gnl			*lst_lines;
	t_reader		*reader;

	lst_lines = NULL;
	if (!(reader = get_reader(&lst_rdrs, fd)) || BUFFER_SIZE < 1
		|| line == NULL || fd < 0)
		return (reader == NULL) ? full_clean(lst_lines, &lst_rdrs, reader) : -1;
	while (reader->size)
	{
		if (check_remain(reader))
			return (full_clean(lst_lines, &lst_rdrs, reader));
		if (search_line_feed(reader))
			break ;
		if (add_lst(&lst_lines, get_line(reader)))
			return (full_clean(lst_lines, &lst_rdrs, reader));
	}
	if ((*line = create_string(lst_lines, reader)) == NULL)
		return (full_clean(lst_lines, &lst_rdrs, reader));
	if (lst_lines != NULL)
		lst_clear(&lst_lines);
	if (reader->eof > 0)
		return (1);
	lst_rdrs = del_one_rdr(&lst_rdrs, reader);
	return (0);
}

int					search_line_feed(t_reader *reader)
{
	int				i;
	char			*s;

	s = reader->p_start;
	i = 0;
	reader->size_remain = 0;
	while (i < reader->size)
	{
		if (s[i] == '\n')
		{
			if (i + 1 < reader->size)
				reader->size_remain = reader->size - i - 1;
			reader->p_del = &s[i];
			reader->size = (int)(reader->p_del - reader->p_start);
			return (1);
		}
		i++;
	}
	return (0);
}

int					check_remain(t_reader *reader)
{
	if (reader->size_remain)
	{
		reader->p_start = reader->p_del + 1;
		reader->size = reader->size_remain;
	}
	else
	{
		if ((reader->size = read(reader->fd, reader->m_buf, BUFFER_SIZE)) < 0)
			return (-1);
		reader->eof = reader->size;
		reader->p_start = reader->m_buf;
	}
	return (0);
}

char				*create_string(t_list_gnl *lst_lines, t_reader *reader)
{
	char			*res;
	char			*str;
	int				i;
	int				l;

	if ((res = (char *)malloc(reader->common_size + reader->size + 1)) == NULL)
		return (NULL);
	reader->common_size = 0;
	i = 0;
	while (lst_lines != NULL)
	{
		str = ((t_line *)lst_lines->content)->str;
		l = 0;
		while (l < ((t_line *)lst_lines->content)->len)
			res[i++] = str[l++];
		lst_lines = lst_lines->next;
	}
	l = 0;
	while (l < reader->size)
		res[i++] = reader->p_start[l++];
	reader->size = -1;
	res[i] = '\0';
	return (res);
}

int					full_clean(t_list_gnl *lst_lines, t_list_gnl **lst_readers,
								t_reader *reader)
{
	lst_clear(&lst_lines);
	*lst_readers = del_one_rdr(lst_readers, reader);
	return (-1);
}
