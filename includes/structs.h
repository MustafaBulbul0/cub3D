#ifndef strducts_H
# define structs_H

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
}	t_game;

typedef struct s_all
{
	t_game		*game;
	t_texture	*texture;
}	t_all;


#endif