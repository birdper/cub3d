
#include "../includes/cub3D.h"

void		ft_init(t_vars *vars, int width, int high, char *title)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, high, title);
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			collapse(int keycode, t_vars *vars)
{
	exit(0);
}

int			ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//DELETE LINE
	printf("%d\n", keycode);
	return (0);
}


