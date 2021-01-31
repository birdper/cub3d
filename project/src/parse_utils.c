#include "../includes/cub3D.h"
#include <fcntl.h>
/**
 *
 * @param file_name
 * @param extension
 * @return
 */
int		ft_check_filename_extension(char *file_name, char *extension)
{
	int fd;
	char *dot;

	file_name = ft_strtrim(file_name, " ");
	if ((dot = ft_strrchr(file_name, '.')) == NULL)
		ft_print_err_exit("The file name does not have an extension");
	if (ft_strncmp(dot, extension, ft_strlen(extension)))
		ft_print_err_exit("Wrong extensions");
	if ((fd = open(file_name, O_RDONLY)) < 0)
		ft_print_err_exit("Couldn't open the file");
	if (read(fd, NULL, 0) < 0)
		ft_print_err_exit("This is not a file");
	return (fd);
}

void ft_print_err_exit(char *message)
{
	ft_putendl_fd("\033[31mError\033[0m", 2);
	ft_putstr_fd("\033[31m", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	ft_putendl_fd("test", 2);
	exit(EXIT_FAILURE);
}