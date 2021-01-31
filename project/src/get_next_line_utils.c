/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:00:33 by nbirdper          #+#    #+#             */
/*   Updated: 2020/12/11 19:01:15 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_reader		*get_reader(t_list_gnl **head, int fd)
{
	t_reader	*reader;
	t_list_gnl		*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		reader = tmp->content;
		if (((t_reader *)tmp->content)->fd == fd)
			return (reader);
		tmp = tmp->next;
	}
	if ((reader = (t_reader *)malloc(sizeof(t_reader))) == NULL)
		return (NULL);
	reader->m_buf = NULL;
	if ((reader->m_buf = (char *)malloc(BUFFER_SIZE)) == NULL)
		return (NULL);
	reader->fd = fd;
	reader->p_del = 0;
	reader->size = -1;
	reader->size_remain = 0;
	reader->common_size = 0;
	add_lst(head, reader);
	return (reader);
}

t_line			*get_line(t_reader *reader)
{
	t_line		*lst_line;
	int			i;

	if ((lst_line = (t_line *)malloc(sizeof(t_line))) == NULL)
		return (NULL);
	lst_line->len = reader->size;
	reader->common_size += reader->size;
	if (reader->size == BUFFER_SIZE)
	{
		lst_line->str = reader->p_start;
		if ((reader->m_buf = (char *)malloc(BUFFER_SIZE)) == NULL)
			return (NULL);
	}
	else
	{
		if ((lst_line->str = (char *)malloc(reader->size)) == NULL)
			return (NULL);
		i = 0;
		while (i < reader->size)
		{
			lst_line->str[i] = reader->p_start[i];
			i++;
		}
	}
	return (lst_line);
}

int				add_lst(t_list_gnl **head, void *content)
{
	t_list_gnl		*tmp;
	t_list_gnl		*new_lst;

	tmp = *head;
	if ((new_lst = (t_list_gnl *)malloc(sizeof(t_list_gnl))) == NULL)
		return (-1);
	new_lst->content = content;
	new_lst->next = NULL;
	if (*head != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
	else
		*head = new_lst;
	return (0);
}

void			lst_clear(t_list_gnl **lst)
{
	t_list_gnl		*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->content != NULL)
		{
			free(((t_line *)(*lst)->content)->str);
			free((*lst)->content);
			free(*lst);
		}
		*lst = tmp;
	}
}

t_list_gnl			*del_one_rdr(t_list_gnl **head, t_reader *reader)
{
	t_list_gnl		*tmp;
	t_list_gnl		*prev;
	t_list_gnl		*ret;

	tmp = *head;
	ret = *head;
	while (tmp && tmp->content != reader)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == *head)
		ret = ((*head)->next == NULL) ? NULL : (*head)->next;
	else
	{
		if (tmp == NULL)
			return (NULL);
		prev->next = tmp->next;
	}
	if ((((t_reader *)tmp->content)->m_buf) != NULL)
		free(((t_reader *)tmp->content)->m_buf);
	free(tmp->content);
	free(tmp);
	tmp = NULL;
	return (ret);
}
