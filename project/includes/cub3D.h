
#ifndef CUB3D_H
# define CUB3D_H
# include "../../minilibx_mms_20200219/mlx.h"
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <string.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_data		data;
}				t_vars;

typedef struct		s_config
{
	int				r_width;
	int				r_hight;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*sprite;
	int				color_floor;
	int				color_ceil;
	unsigned char	checksum;
}					t_config;

typedef struct		s_map
{
	char			player;
}					t_map;

int				ft_close(int keycode, t_vars *vars);
int				collapse(int keycode, t_vars *vars);
int				ft_create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);


void			ft_init(t_vars *vars, int width, int high, char *title);

// PARSER CONFIG
void			ft_print_conf(t_config *conf);

void			ft_parse(char *file_name);
void			ft_selector(char *line, t_config *conf);
int				ft_get_color(char *line, t_config *conf, int pos);
void			ft_get_resolution(char *line, t_config *conf);
char			*ft_get_texture(char *line, t_config *conf, int pos);

// PARSER MAP
void			ft_parse_map(int fd);

int ft_check_map(int c);
int		ft_check_all(int c);
void		ft_border_lines(char *line, t_list **head);





//UTILS
int				ft_check_filename_extension(char *file_name, char *extension);
void			ft_print_err_exit(char *message);




#endif
