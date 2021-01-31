#include "../includes/cub3D.h"
#include <fcntl.h>
/**
 *
 * @param file_name
 * @param extension
 * @return
 */
int ft_check_filename_extension(char *file_name, char *extension, char *name_func)
{
	int fd;
	char *dot;

	file_name = ft_strtrim(file_name, " ");
	if ((dot = ft_strrchr(file_name, '.')) == NULL)
		ft_print_err_exit("The file name does not have an extension", name_func);
	if (ft_strncmp(dot, extension, ft_strlen(extension)))
		ft_print_err_exit("Wrong extensions", name_func);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		ft_print_err_exit("Couldn't open the file", name_func);
	if (read(fd, NULL, 0) < 0)
		ft_print_err_exit("This is not a file", name_func);
	return (fd);
}

void ft_print_err_exit(char *message, char *name_func)
{
	ft_putstr_fd("\033[31mError -> ", 2);
	ft_putendl_fd(name_func, 2);

//	ft_putstr_fd("\033[31m", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}