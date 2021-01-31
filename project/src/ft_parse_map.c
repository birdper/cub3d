#include "../includes/cub3D.h"

static int		ft_check_player(int c)
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



static int		ft_check_all(int c)
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



static void		ft_border_lines(char *line, t_list **head)
{
	int i;
	char *name_func = "ft_border_lines";

	i = 0;
	if (ft_isempty_str(line))
	{
		free(line);
		return;
	}
	while (line[i] != 0)
	{
		if (ft_strchr(" 12", line[i]))
			ft_print_err_exit("Incorrect map", name_func);
		i++;
	}
	ft_lstadd_back(head, ft_lstnew(line));

}



void ft_parse_map(int fd)
{
	t_list	*lst_map;
	char	*line;
	int		dir_player;
	char *name_func = "parse_map()";

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
				ft_print_err_exit("incorrect map", name_func);
			if (ft_foreach(line, ft_check_player))
			{
				if (dir_player)
					ft_print_err_exit("incorrect map", name_func);
				dir_player = 1;
			}
			ft_lstadd_back(&lst_map, ft_lstnew(line));
		}
	}
}

