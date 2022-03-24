/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:43:26 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:49:45 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	isformat(char *s1, char *s2)
{
	size_t	s1_ln;
	size_t	s2_ln;

	s1_ln = ft_strlen(s1);
	s2_ln = ft_strlen(s2);
	return (!ft_strcmp(s1 + (s1_ln - s2_ln), s2));
}

void	exit_failure(t_data *data, char *error)
{
	(void) data;
	if (error)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
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
	data->map.rows = (int *)v_malloc(sizeof(int) * data->map.cols);
	data->map.map = ft_split(map, '\n');
	while (++i < data->map.cols - 1)
		data->map.rows[i] = (int)ft_strlen(data->map.map[i]);
	i = -1;
	data->map.m_mask = (int **)v_malloc(sizeof(int *) * data->map.cols);
	while (++i < data->map.cols - 1)
		data->map.m_mask[i] = (int *)v_malloc(sizeof(int) * data->map.rows[i]);
	free(map);
}

void	map_pars(t_data	*data, char	*one_line, char **map, int *i)
{
	char	*tmp_map;

	if (*i <= CEILING_COLOR)
	{
		if (map_fill(data, one_line, *i) == 0)
			(*i)++;
	}
	else if (one_line != '\0')
	{
		tmp_map = *map;
		if (!*map)
			*map = ft_strdup(one_line);
		else
			*map = ft_strjoin(*map, one_line);
		*map = ft_strjoin(*map, "\n");
		free(tmp_map);
		data->map.cols++;
	}
}

void	*parser(t_data *data, char *filename)
{
	char	*one_line;
	int		i;
	char	*map;
	int		fd;

	map = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_failure(data, "1. Sorry, filename could not be found");
	if (!isformat(filename, ".cub"))
		exit_failure(data, "2. Sorry, extension is not valid");
	ft_bzero(data, sizeof(t_data));
	i = 1;
	while (get_next_line(fd, &one_line))
	{
		map_pars(data, one_line, &map, &i);
		free(one_line);
	}
	free(one_line);
	split_map_get_rows(data, map);
	if (map_check(data) != 0)
		exit (1);
	return (NULL);
}
