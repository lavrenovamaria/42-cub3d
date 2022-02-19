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
int		isformat(char *s1, char *s2)
{
	size_t	s1_ln;
	size_t	s2_ln;

	s1_ln = ft_strlen(s1);
	s2_ln = ft_strlen(s2);
	return (!ft_strcmp(s1 + (s1_ln - s2_ln), s2));
}

// void	init_data(t_cub *cub)
// {
// 	cub->NO = NULL;
// 	cub->SO = NULL;
// 	cub->WE = NULL;
// 	cub->EA = NULL;
// 	cub->F[0] = -1;
// 	cub->F[1] = -1;
// 	cub->F[2] = -1;
// 	cub->C[0] = -1;
// 	cub->C[1] = -1;
// 	cub->C[2] = -1;
// 	cub->map = NULL;
// 	cub->id_done = false;
// 	cub->map_done = false;
// }

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

int parser(t_data *data, char *filename)
{
	
	if(data->fd = open(filename, O_RDONLY) < 0 || !isformat(filename, ".cub"))
		exit_failure(data, "Sorry, filename could not be found or extension is not valid");
	while (get_next_line(data->fd, data->line))
	{

	}
	return(1);
}

int main(int ac, char **av)
{
	t_data data;
	
	if(ac != 2)
		exit_failure(&data, "Wrong number of arguments");
	ft_bzero(&data, sizeof(t_data));
	return(0);
}

