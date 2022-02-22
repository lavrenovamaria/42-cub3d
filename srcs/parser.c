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

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && (i + 1) < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize)
		dest[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (j);
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

int	ft_strncmp(const char *str1, const char *str2, size_t count_size)
{
	size_t	i;

	i = 0;
	if (count_size == 0)
		return (0);
	while (*str1 != '\0' && (*str1 == *str2) && (i < count_size - 1))
	{
		str1++;
		str2++;
		count_size--;
	}
	return ((unsigned char)*str1 - *str2);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (*(src + i))
		i++;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	while (i > 0)
	{
		*(dst + i) = *(src + i);
		i--;
	}
	*dst = *src;
	return (dst + i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*res;
	size_t	str_len1;
	size_t	str_len2;

	if (!str1 || !str2)
		return (NULL);
	str_len1 = ft_strlen(str1);
	str_len2 = ft_strlen(str2);
	res = (char *)malloc(sizeof(char) * (str_len1 + str_len2 + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str1, (str_len1 + 1));
	ft_strlcat(res, str2, (str_len1 + str_len2 + 1));
	return (res);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	offset;
	size_t	src_i;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	offset = d_len;
	src_i = 0;
	if (size < d_len)
		return (size + s_len);
	while ((*(src + src_i)) && (src_i + d_len + 1 < size))
	{
		*(dst + offset) = (src[src_i]);
		src_i++;
		offset++;
	}
	*(dst + offset) = '\0';
	return (d_len + s_len);
}
	//const char *ext = ".jpeg";
	//size_t xlen = strlen(ext);
	//size_t slen = strlen(argv[1]);
	//int found = strcmp(argv[1] + slen - xlen, ext) == 0;
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	if (len <= (unsigned int)ft_strlen(s))
		str = ft_calloc(len + 1, sizeof(char));
	else
		str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
char	*ft_strchr(const char *str, int ch)
{
	while (*str != (char)ch)
		if (!*str++)
			return (0);
	return ((char *)str);
}
char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	while (ft_strchr(set, *s) != 0 && *s)
		s++;
	len = ft_strlen(s);
	while (ft_strchr(set, s[len]) != 0 && len > 0)
		len--;
	str = ft_substr(s, 0, len + 1);
	if (!str)
		return (NULL);
	return (str);
}
size_t	ft_nbr_word(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str != '\0')
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

void	ft_free_mem(char **mem)
{
	int	i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

size_t	ft_word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str == c)
		str++;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_pre_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s)
		return (NULL);
	i = ft_nbr_word(s, c);
	str = ft_calloc(i + 1, sizeof(char *));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (i > j)
	{
		while (*s == c)
			s++;
		str[j] = ft_substr (s, 0, ft_word_len (s, c));
		if (str[j++] == NULL)
		{
			ft_free_mem(str);
			return (NULL);
		}
		s += ft_word_len (s, c);
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_pre_split (s, c);
	if (!str)
		return (NULL);
	return (str);
}


///////////////////////////////


void print_data(t_data *data)
{
	printf("________________________________________\n");
	if (data == NULL)
	{
		printf("Data struct not allocated\n");
		printf("________________________________________\n");
		return ;
	}
	if (data->NO != NULL)
		printf("NO : %s\n", data->NO);
	else
		printf("NO : NULL\n");
	if (data->SO != NULL)
		printf("SO : %s\n", data->SO);
	else
		printf("SO : NULL\n");
	if (data->WE != NULL)
		printf("WE : %s\n", data->WE);
	else
		printf("WE : NULL\n");
	if (data->EA != NULL)
		printf("EA : %s\n", data->EA);
	else
		printf("EA : NULL\n");
	printf("Floor RGB : %d %d %d\n", data->F[0], data->F[1], data->F[2]);
	printf("Ceiling RGB : %d %d %d\n", data->C[0], data->C[1], data->C[2]);
	int i = -1;
	while (data->map.map[++i])
	{
		printf("%s\n", data->map.map[i]);
	}
	printf("________________________________________\n");
}


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

int		overlap_error(t_data *data, int type)
{
	if (data->map.info_check[type - 1] == type)
		error_exit("overlap error");
	else
		data->map.info_check[type - 1] = type;
	return (type - 1);
}

int		check_gnl(t_data *data, char *one_line)
{
	if (!ft_strncmp(one_line, "NO ", 3))
		return (overlap_error(data, NORTH));
	else if (!ft_strncmp(one_line, "SO ", 3))
		return (overlap_error(data, SOUTH));
	else if (!ft_strncmp(one_line, "WE ", 3))
		return (overlap_error(data, WEST));
	else if (!ft_strncmp(one_line, "EA ", 3))
		return (overlap_error(data, EAST));
	else if (!ft_strncmp(one_line, "F ", 2))
		return (overlap_error(data, FLOOR_COLOR));
	else if (!ft_strncmp(one_line, "C ", 2))
		return (overlap_error(data, CEILING_COLOR));
	else if (one_line[0] == 0)
		return (7);
	else
		error_exit("invalid map info");
	return (-1);
}

int		isformat(char *s1, char *s2)
{
	size_t	s1_ln;
	size_t	s2_ln;

	s1_ln = ft_strlen(s1);
	s2_ln = ft_strlen(s2);
	return (!ft_strcmp(s1 + (s1_ln - s2_ln), s2));
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

void	split_map_get_rows(t_data *data, char *map)
{
	int	i;

	i = -1;
	data->map.rows = (int*)var_malloc(sizeof(int) * data->map.cols);
	data->map.map = ft_split(map, '\n');
	while (++i < data->map.cols - 1)
		data->map.rows[i] = (int)ft_strlen(data->map.map[i]);
	i = -1;
	data->map.map_mask = (int**)var_malloc(sizeof(int*) * data->map.cols);
	while (++i < data->map.cols - 1)
		data->map.map_mask[i] = (int*)var_malloc(sizeof(int) * data->map.rows[i]);
	free(map);
}

int	num_size(int num)
{
	int	size;

	size = 1;
	while (num / 10 != 0)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

int map_fill(t_data *data, char *one_line, int i)
{
	int j = 0;
	char	**tmp_split;

	if (check_gnl(data, one_line) == 7)
		return (1);
	if(i == NORTH)
		data->NO =  ft_strdup(one_line);
	else if(i == SOUTH)
		data->SO =  ft_strdup(one_line);
	else if(i == WEST)
		data->WE =  ft_strdup(one_line);
	else if(i == EAST)
		data->EA =  ft_strdup(one_line);
	else if(i == FLOOR_COLOR)
	{
		//tmp_split = ft_split(one_line, ',');
		//while(j++ < 3)
		//		data->F[j] = ft_atoi(tmp_split[j]);
		while (one_line[j] < 48 || one_line[j] > 57)
			j++;
		data->F[0] = ft_atoi(&one_line[j]);
		j+= num_size(data->F[0]);
		data->F[1] = ft_atoi(&one_line[j]);
		j+= num_size(data->F[1]);
		data->F[2] = ft_atoi(&one_line[j]);
	}
	else if(i == CEILING_COLOR)
	{
		//tmp_split = ft_split(one_line, ',');
		//while(j++ < 3)
		//		data->F[j] = ft_atoi(tmp_split[j]);
		while (one_line[j] < 48 || one_line[j] > 57)
			j++;
		data->C[0] = ft_atoi(&one_line[j]);
		j+= num_size(data->C[0]);
		data->C[1] = ft_atoi(&one_line[j]);
		j+= num_size(data->C[1]);
		data->C[2] = ft_atoi(&one_line[j]);
	}
	return (0);
}

int	map_check(t_data *data)
{
	int 	i;
	int 	j;
	int		length;
	char	*tmp_map;
	
	i = 1;
	j = 0;
	while (data->map.map[0][j] != '\0')
	{
		while (data->map.map[0][j] == ' ')
			j++;
		if (data->map.map[0][j] == '\n')
			break ;
		if (data->map.map[0][j] != '1')
		{
			printf("wrong map error 1\n");
			return (1);
		}
		j++;
	}
	while (data->map.map[i] != NULL)
	{
		tmp_map = ft_strtrim(data->map.map[i], "\t ");
		j = ft_strlen(tmp_map);
		//printf("length = %d\n", j);
		//printf("string: %s\n0 and last elsem: %c and %c\n", tmp_map, tmp_map[0], tmp_map[j - 1]);
		if (tmp_map[0] != '1' || tmp_map[j - 1] != '1')
		{
			printf("wrong map error in %d string\n", i + 1);
			return (1);
		}
		i++;
	}
	while (data->map.map[i - 1][j] != '\0')
	{
		while (data->map.map[i - 1][j] == ' ')
			j++;
		if (data->map.map[i - 1][j] == '\n')
			break ;
		if (data->map.map[i - 1][j] != '1')
		{
			printf("wrong map error 1\n");
			return (1);
		}
		j++;
	}
	return (0);
}

void *parser(t_data *data, char *filename)
{
	char *one_line;
	int i = 1;
	char *tmp_map;
	char *map = 0;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_failure(data, "1. Sorry, filename could not be found");
	if(!isformat(filename, ".cub"))
		exit_failure(data, "2. Sorry, extension is not valid");
	//data = (t_data *)malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	//init_data(data);
	//write(1, "0", 1);
	while (get_next_line(fd, &one_line))
	{
		//write(1, "1", 1);
		// printf("%s\n", one_line);
		// fflush(NULL);
		if (i <= CEILING_COLOR)
		{
			if (map_fill(data, one_line, i) == 0)
				i++;
		}
			//data->map.info_map[check_gnl(data, one_line)] = ft_strdup(one_line);
		else if (one_line != '\0')
		{
			tmp_map = map;
			if (!map)
				map = ft_strdup(one_line);
			else
				map = ft_strjoin(map, one_line);
			map = ft_strjoin(map, "\n");
			free(tmp_map);
			data->map.cols++;
		}
		free(one_line);
	}
	free(one_line);
	split_map_get_rows(data, map);
	map_check(data);
	print_data(data);
	return(NULL);
}

int main(int ac, char **av)
{
	t_data data;
	char *file = av[1];

	if(ac != 2)
		exit_failure(&data, "Wrong number of arguments");
	if(parser(&data, file))
		printf("yes");
	return(0);
}

