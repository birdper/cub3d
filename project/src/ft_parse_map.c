#include "../includes/cub3D.h"

int		ft_check_map(int c)
{
	if (ft_strchr(" 012", c))
		return (1);
//	if (ft_strchr("ESWN", c))
//	{
//		if (FLAG ON)
//			return (0);
//		set FLAG
//		return (1);
//	}
	return (0);
}



int		ft_check_all(int c)
{
	if (ft_strchr(" 012", c))
		return (1);
	if (ft_strchr("ESWN", c))
	{
//		 if (FLAG ON)
//			return (0);
//		set FLAG
		return (1);
	}
	return(0);
}



void		ft_border_lines(char *line, t_list **head)
{
	if (ft_isempty_str(line))
	{
		free(line);
		return;
	}
	if (!ft_foreach(line, ft_strchr("NSWE", *line)))
		ft_print_err_exit("Incorrect map");
	else
		ft_lstadd_back(head, ft_lstnew(line));
}



void ft_parse_map(int fd)
{
	t_list	*lst_map;
	char	*line;
	int		dir_player;

	dir_player = 0;
	if (get_next_line(fd, &line))
	{
		ft_border_lines(line, &lst_map);
		while (get_next_line(fd, &line))
		{
			if (ft_isempty_str(line))
			{
				free(line);
				continue;
			}
			if (!ft_foreach(line, ft_check_all))
				ft_print_err_exit("incorrect map");
			if (ft_foreach(line, ft_check_all))
			{
				if (dir_player)
					ft_print_err_exit("incorrect map");
				dir_player = 1;
			}
			ft_lstadd_back(&lst_map, ft_lstnew(line));
		}
	}
}

