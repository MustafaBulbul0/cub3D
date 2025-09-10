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

typedef struct s_game
{
	char	**map;
	int		*player_position; // x,y   col,row

	double	*sin_tab;
	double	*cos_tab;
}	t_game;

typedef struct s_mlx
{
	void	*mlx;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	void	*win;
}	t_mlx;

typedef struct s_all
{
	t_game		*game;
	t_texture	*texture;
	t_mlx		*mlx;
}	t_all;

#endif