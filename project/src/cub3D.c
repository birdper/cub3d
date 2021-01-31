

#include "../includes/cub3D.h"
//#include "../minilibx_mms_20200219/mlx.h"




void 		draw_line(t_data *data, double x1, double y1,
									double x2, double y2)
{
	double		k;
//	double		kx;
	double		y;
	double		x;
	int			h;


	h = fabs(x2 - x1) + 1;
	k = (y2 - y1) / (x2 - x1);
	while (h--)
	{
		my_mlx_pixel_put(data, x1, y1, 0x00FF0000);
		x1 ++;
		y1 += k;
	}

}



int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	t_config	*conf;

	img = vars.data;
	ft_init(&vars, 640, 480, "prj");

	ft_parse(argv[1]);

	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
									&img.line_length, &img.endian);

	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_hook(vars.win, 17, 1L<<1, collapse, &vars);

	my_mlx_pixel_put(&img, 0, 0, 0x00FFFFFF);
	my_mlx_pixel_put(&img, 140, 0, 0x00FFFFFF);
	my_mlx_pixel_put(&img, 0, 80, 0x00FFFFFF);

	draw_line(&img, 0, 80, 20, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello");
//	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_loop_hook(vars.mlx render_next_frame, &vars);
	mlx_loop(vars.mlx);
}

