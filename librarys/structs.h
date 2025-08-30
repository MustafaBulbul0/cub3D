#ifndef strducts_H
# define structs_H

typedef struct s_texture
{
	/* data */
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