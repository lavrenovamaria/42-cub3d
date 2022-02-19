#include "get_next_line.h"

int	ft_find_nl(char *str)
{
	int	ind_nl;

	if (str == NULL)
		return (0);
	ind_nl = 0;
	while (str[ind_nl] && str[ind_nl] != '\n')
		ind_nl++;
	if (str[ind_nl] != '\n')
		return (-1);
	return (ind_nl);
}

int	ft_split_line(char **str, char **line, int index)
{
	int	len;

	*line = ft_substr_gnl(*str, 0, index);
	++index;
	len = ft_strlen_gnl(*str + index) + 1;
	*str = ft_memmove_gnl(*str, *str + index, len);
	return (1);
}

int	ft_return_line(char **str, char **line, int ret, int index)
{
	if (*str == NULL || ret < 0)
		return (-1);
	index = ft_find_nl (*str);
	if (index != -1)
		return (ft_split_line (str, line, index));
	else if (*str)
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[256];
	char		buffstr[BUFFER_SIZE + 1];
	int			index;
	int			ret;

	ret = read(fd, buffstr, BUFFER_SIZE);
	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0) || fd > 256 || ret < 0)
		return (-1);
	while (ret > 0)
	{
		buffstr[ret] = '\0';
		str[fd] = ft_strjoin_gnl (str[fd], buffstr);
		index = ft_find_nl (str[fd]);
		if (index != -1)
			return (ft_split_line (&str[fd], line, index));
		ret = read(fd, buffstr, BUFFER_SIZE);
	}
	if (str[fd] == NULL)
	{
		*line = malloc(1);
		**line = '\0';
		return (0);
	}
	return (ft_return_line (&str[fd], line, ret, index));
}

// int		main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc == 1)
// 		fd = 0;
// 	else if (argc == 2)
// 		fd = open(argv[1], O_RDONLY);
// 	else
// 		return (2);
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		ft_putendl_fd(line, 1);
// 		free(line);
// 	}
// 	if (argc == 2)
// 		close(fd);
// }
