#include "../inc/parser.h"
///////////
void	*ft_memset(void *str, int ch, size_t size_buff)
{
	char	*p;

	p = str;
	while (size_buff--)
		*p++ = (char)ch;
	return (str);
}

void	ft_bzero(void *dst, size_t num_bytes)
{
	ft_memset(dst, 0, num_bytes);
}

void	ft_putstr_fd(char const *s, int fd)
{
	while (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *ltr)
{
	int	i;

	i = 0;
	while (*ltr != '\0')
	{
		i++;
		ltr++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}



	//const char *ext = ".jpeg";
	//size_t xlen = strlen(ext);
	//size_t slen = strlen(argv[1]);
	//int found = strcmp(argv[1] + slen - xlen, ext) == 0;

/////////////////////////


// void print_data(t_cub *cub)
// {
// 	t_map *tmp;
// 	printf("________________________________________\n");
// 	if (cub == NULL)
// 	{
// 		printf("Data struct not allocated\n");
// 		printf("________________________________________\n");
// 		return ;
// 	}
// 	if (cub->NO != NULL)
// 		printf("NO : %s\n", cub->NO);
// 	else
// 		printf("NO : NULL\n");
// 	if (cub->SO != NULL)
// 		printf("SO : %s\n", cub->SO);
// 	else
// 		printf("SO : NULL\n");
// 	if (cub->WE != NULL)
// 		printf("WE : %s\n", cub->WE);
// 	else
// 		printf("WE : NULL\n");
// 	if (cub->EA != NULL)
// 		printf("EA : %s\n", cub->EA);
// 	else
// 		printf("EA : NULL\n");
// 	printf("Floor RGB : %d %d %d\n", cub->F[0], cub->F[1], cub->F[2]);
// 	printf("Ceiling RGB : %d %d %d\n", cub->C[0], cub->C[1], cub->C[2]);
// 	if (cub->id_done == true)
// 		printf("ID done and valid? : Yes\n");
// 	else
// 		printf("ID done and valid? : No\n");
// 	if (cub->map_done == true)
// 		printf("Map done and valid? : Yes\n");
// 	else
// 		printf("Map done and valid? : No\n");
// 	tmp = cub->map;
// 	if (tmp == NULL)
// 		printf("Nothing stored in map\n");
// 	while(tmp != NULL)
// 	{
// 		printf("x = %d\t y = %d\t o = %c\n", tmp->x, tmp->y, tmp->o);
// 		tmp = tmp->next;
// 	}
// 	printf("________________________________________\n");
// }

int		isformat(char *s1, char *s2)
{
	size_t	s1_ln;
	size_t	s2_ln;

	s1_ln = ft_strlen(s1);
	s2_ln = ft_strlen(s2);
	return (!ft_strcmp(s1 + (s1_ln - s2_ln), s2));
}
//указатели на название NO/SO/WE/EA и вариации цвета пола и потолка
void	init_data(t_data *data)
{
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->F[0] = 0;
	data->F[1] = 0;
	data->F[2] = 0;
	data->C[0] = 0;
	data->C[1] = 0;
	data->C[2] = 0;
}

void	exit_failure(t_data *data, char *error)
{
	//зафришить всё перед выходом?
	if (error)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(1);
	}
	exit(0);
}

t_data *parser(t_data *data, char *filename)
{
	char *one_line;
	int i = -1;
	char *tmp_map;
	char *map = 0;

	if(data->fd = open(filename, O_RDONLY) < 0 || !isformat(filename, ".cub"))
		exit_failure(data, "Sorry, filename could not be found or extension is not valid");
	ft_bzero(&data, sizeof(t_data));
	init_data(data);
	while (get_next_line(data->fd, data->line))
	{
		if (*one_line != '\0' && ++i <= CEILING_COLOR)
			data->map->info_map[check_gnl(data, one_line)] = ft_strdup(one_line);
		else if (*one_line != '\0')
		{
			tmp_map = map;
			if (!map)
				map = ft_strdup(one_line);
			else
				map = ft_strjoin(map, one_line);
			free(tmp_map);
			data->map->cols++;
		}
		free(one_line);
		free(data->line);
		print_data(data->line);
		split_map_get_rows(data, map);
	}
	return(data);
}

int main(int ac, char **av)
{
	t_data data;

	if(ac != 2)
		exit_failure(&data, "Wrong number of arguments");
	return(0);
}

