#include "../../includes/cub3d.h"

char	**strdup_2d(char **map)
{
	char	**new_map;
	int		len;
	int		i;

	i =	0;
	len = 0;
	while (map[len])
		len++;
	new_map = ft_calloc(len + 1, sizeof(char *));
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (new_map);
}

char	**special_split(char *s)
{
	char	**spl;
	int		i;
	int		j;
	int		k;
	int		lines;

	lines = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			lines++;
		i++;
	}
	spl = malloc(sizeof(char *) * (lines + 1));
	if (!spl)
		return (NULL);
	j = 0;
	k = 0;
	i = 0;
	spl[j] = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			spl[j][k] = '\0';
			j++;
			k = 0;
			spl[j] = malloc(ft_strlen(s) + 1);
		}
		else
		{
			spl[j][k++] = s[i];
		}
		i++;
	}
	spl[j][k] = '\0';
	spl[j + 1] = NULL;
	return (spl);
}

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

