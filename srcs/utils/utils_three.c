#include "../../includes/cub3d.h"
#include <stdio.h>

void	flood_fill(char **map, int xz[2], int row, int col)
{
	int	new_xz[2];

	if (xz[0] < 0 || xz[1] < 0 || xz[0] >= row || xz[1] >= col)
		return ;
	if (!is_space(map[xz[0]][xz[1]]))
		return ;
	map[xz[0]][xz[1]] = 'F';
	new_xz[0] = xz[0] + 1;
	new_xz[1] = xz[1];
	flood_fill(map, new_xz, row, col);
	new_xz[0] = xz[0] - 1;
	new_xz[1] = xz[1];
	flood_fill(map, new_xz, row, col);
	new_xz[0] = xz[0];
	new_xz[1] = xz[1] + 1;
	flood_fill(map, new_xz, row, col);
	new_xz[0] = xz[0];
	new_xz[1] = xz[1] - 1;
	flood_fill(map, new_xz, row, col);
}
