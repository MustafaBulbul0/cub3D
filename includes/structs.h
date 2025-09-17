#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	char	*f;
	char	*c;

	int	f_color[3];
	int	c_color[3];
}	t_texture;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}	t_keys;

typedef struct s_ray
{
	double	ray_angle;
	double	distance;
	int		wall_hit;
	double	wall_x;
	double	wall_y;
	int		side;

	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}	t_ray;

typedef struct s_game
{
	char	**map;
	double	player_angle;
	double	player_x;
	double	player_y;

	t_keys	keys;
	double	*sin_tab;
	double	*cos_tab;
}	t_game;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	*no_texture;
	t_image	*so_texture;
	t_image	*we_texture;
	t_image	*ea_texture;
	t_image	*screen;
}	t_mlx;

typedef struct s_all
{
	t_game		*game;
	t_texture	*texture;
	t_mlx		*mlx;
}	t_all;

#endif