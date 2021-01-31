#include <fcntl.h>
#include "../includes/cub3D.h"

// mapa
// numbers parametres

/**
 * @param file_name
 *
 **/

void		ft_print_conf(t_config *conf)
{
	printf("width = %d\n", conf->r_width);
	printf("height = %d\n", conf->r_hight);
	printf("color_floor = %d\n", conf->color_floor);
	printf("color_ceil = %d\n", conf->color_ceil);
	printf("S = %d\n", conf->color_ceil);
}

void			ft_parse(char *file_name)
{
	t_config	*conf;
	char		*line;
	int			fd;
	int			i;

	conf = (t_config *)malloc(sizeof(t_config));
	fd = ft_check_filename_extension(file_name, ".cub", "parse()");
	while (get_next_line(fd, &line))
	{
		i = 0;
		if (!ft_isempty_str(line))
		{
			while (ft_isspace(line[i]))
				i++;
			ft_selector(line + i, conf);
		}
		free(line);
		if (conf->checksum == 255)
			break;
	}
	ft_parse_map(fd);

//	if (conf->checksum == 255)
		printf("mask %d\n", conf->checksum);
	ft_print_conf(conf);
	close(fd);
}

void			ft_selector(char *line, t_config *conf)
{
	if (*line == 'R')
		ft_get_resolution(line + 1, conf);
	if (*line == 'F')
		conf->color_floor = ft_get_color(line + 1, conf, 2);
	if (*line == 'C')
		conf->color_ceil = ft_get_color(line + 1, conf, 3);
	if (*line == 'S')
	{
		conf->sprite = ft_get_texture(line + 1, conf, 4);
		// DELTE THIS!
		printf("path %s", conf->sprite);

	}
	if (*line == 'N' && *(line + 1) == 'O')
		conf->NO = ft_get_texture(line + 2, conf, 5);
	if (*line == 'S' && *(line + 1) == 'O')
		conf->SO = ft_get_texture(line + 2, conf, 6);
	if (*line == 'W' && *(line + 1) == 'E')
		conf->WE = ft_get_texture(line + 2, conf, 7);
	if (*line == 'E' && *(line + 1) == 'A')
		conf->EA = ft_get_texture(line + 2, conf, 8);
}

void			ft_get_resolution(char *line, t_config *conf)
{
	char		**argv;
	int			argc;
	char *name_func = "get_resolution()";

//	if (conf->checksum & (1 << 1))
//		ft_print_err_exit("dubl R");
	argv = ft_split(line, ' ');
	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	if (argc != 2)
		ft_print_err_exit("Error in ft_get_resolution() Invalid number of arguments.", name_func);
	argc = 0;
	while (argc < 2)
		if ((!ft_foreach(argv[argc++], ft_isdigit)))
			ft_print_err_exit("Error in ft_get_resolution() Invalid arguments.", name_func);
	conf->r_width = ft_atoi(argv[0]);
	conf->r_hight = ft_atoi(argv[1]);
	conf->checksum |= (1 << 1);
	free(argv);
}

int ft_get_color(char *line, t_config *conf, int pos)
{
	int			rgb[3];
	int			argc;
	char		**argv;
	char		*tmp;
	int			i;
	char *name_func = "get_color()";

	argv = ft_split(line, ',');
	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	if (argc != 3)
		ft_print_err_exit("ft_parse_color(): Invalid number of arguments.", name_func);
	i = 0;
	while (i < argc)
	{
		tmp = ft_strtrim(argv[i], " ");
		if (!ft_foreach(tmp, ft_isdigit))
			ft_print_err_exit("ft_parse_color(): Invalid arguments.", name_func);
		rgb[i] = ft_atoi(argv[i]);
		if (rgb[i] > 255 || ft_isempty_str(tmp))
			ft_print_err_exit("ft_parse_color(): Invalid arguments.", name_func);
		free(tmp);
		i++;
	}
	free(argv);
	conf->checksum |= (1 << pos);
	return (ft_create_trgb(0, rgb[0], rgb[1], rgb[2]));
}

char *ft_get_texture(char *line, t_config *conf, int pos)
{
	char		**arr;
	char		*filename;
	char *name_func = "get_texture()";


	arr = ft_split(line, ' ');
	// DELTE THIS!
	printf("path %s\n", arr[0]);
	ft_check_filename_extension(arr[0], ".xpm", name_func);
	filename = ft_strdup(arr[0]);
	free(arr);
	conf->checksum |= (1 << pos);
	return (filename);
}
