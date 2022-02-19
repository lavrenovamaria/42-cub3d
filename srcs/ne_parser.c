#include "../inc/parser.h"

void	error_exit(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(-1);
}

void	*var_malloc(size_t size)
{
	void	*var;

	var = ft_calloc(1, size);
	if (!var)
		error_exit("malloc error");
	return (var);
}

int		overlap_error(t_info *info, int type)
{
	if (info->info_check[type] == type)
		error_exit("overlap error");
	else
		info->info_check[type] = type;
	return (type);
}

int		check_gnl(t_info *info, char *one_line)
{
	if (!ft_strncmp(one_line, "R ", 2))
		return (overlap_error(info, RESOLUTION));
	else if (!ft_strncmp(one_line, "NO ", 3))
		return (overlap_error(info, NORTH));
	else if (!ft_strncmp(one_line, "SO ", 3))
		return (overlap_error(info, SOUTH));
	else if (!ft_strncmp(one_line, "WE ", 3))
		return (overlap_error(info, WEST));
	else if (!ft_strncmp(one_line, "EA ", 3))
		return (overlap_error(info, EAST));
	else if (!ft_strncmp(one_line, "S ", 2))
		return (overlap_error(info, SPRITE));
	else if (!ft_strncmp(one_line, "F ", 2))
		return (overlap_error(info, FLOOR_COLOR));
	else if (!ft_strncmp(one_line, "C ", 2))
		return (overlap_error(info, CEILING_COLOR));
	else
		error_exit("invalid map info");
	return (-1);
}

void	split_map_get_rows(t_info *info, char *map)
{
	int	i;

	i = -1;
	info->rows = (int*)var_malloc(sizeof(int) * info->cols);
	info->map = ft_split(map, '\n');
	while (++i < info->cols)
		info->rows[i] = (int)ft_strlen(info->map[i]);
	i = -1;
	info->map_mask = (int**)var_malloc(sizeof(int*) * info->cols);
	while (++i < info->cols)
		info->map_mask[i] = (int*)var_malloc(sizeof(int) * info->rows[i]);
	free(map);
}


void	get_map(int fd, t_info *info)
{
	char	*one_line;
	int		i;
	char	*temp_map;
	char	*map;

	i = -1;
	map = 0;
	while (get_next_line(fd, &one_line) || *one_line != '\0')
	{
		if (*one_line != '\0' && ++i <= CEILING_COLOR)
			info->info_map[check_gnl(info, one_line)] = ft_strdup(one_line);
		else if (*one_line != '\0')
		{
			temp_map = map;
			if (!map)
				map = ft_strdup(one_line);
			else
				map = ft_strjoin(map, one_line);
			free(temp_map);
			info->cols++;
		}
		free(one_line);
	}
	free(one_line);
	split_map_get_rows(info, map);
}


int main(int ac, char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	get_map(fd, &game->info);
	return (0);
}

//1. Открыть файл и проверить на ошибки формат
//2. Проверить, что контент в файле лежит согласно правилам, если да, сохранить
//3.
//
//
//
//
