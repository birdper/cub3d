/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:00:39 by nbirdper          #+#    #+#             */
/*   Updated: 2020/12/11 19:01:01 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_list_gnl
{
	void				*content;
	struct s_list_gnl	*next;
}						t_list_gnl;

typedef struct			s_line
{
	char				*str;
	int					len;
}						t_line;

typedef struct			s_reader
{
	int					fd;
	int					eof;
	char				*m_buf;
	char				*p_start;
	char				*p_del;
	int					size;
	int					common_size;
	int					size_remain;
}						t_reader;

int						get_next_line(int fd, char **line);
t_reader				*get_reader(t_list_gnl **head, int fd);
t_line					*get_line(t_reader *reader);
int						check_remain(t_reader *reader);
int						search_line_feed(t_reader *reader);
int						add_lst(t_list_gnl **head, void *content);
char					*create_string(t_list_gnl *lst_lines, t_reader *reader);
void					lst_clear(t_list_gnl **lst);
t_list_gnl				*del_one_rdr(t_list_gnl **head, t_reader *reader);
int						full_clean(t_list_gnl *lst_lines,
									t_list_gnl **lst_readers, t_reader *reader);

#endif
