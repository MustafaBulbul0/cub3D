#include "../../includes/cub3d.h"

void	clear_2d_pointer(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*ft_realloc(char *s, int size)
{
	char	*new_s;
	int		i;

	if (size == 0)
		return (free(s), NULL);
	new_s = ft_calloc(size + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		new_s[i] = s[i];
		i++;
	}
	free(s);
	return (new_s);
}

void	exit_print(char *s)
{
	printf("%s\n", s);
	free(s);
	exit (EXIT_FAILURE);
}
