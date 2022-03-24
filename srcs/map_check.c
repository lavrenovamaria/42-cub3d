/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:31:23 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:32:07 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int	closed_map(t_data *data, int i, int j)
{
	while (data->map.map[i + 1] != NULL)
	{
		while (data->map.map[i][j] != '\0')
		{
			while (data->map.map[i][j] == ' ')
				j++;
			if (data->map.map[i][j] != '1' && data->map.map[i - 1][j] == ' ')
			{
				printf("Error\nwrong map\n");
				return (1);
			}
			if (data->map.map[i][j] != '1' && data->map.map[i + 1][j] == ' ')
			{
				printf("Error\nwrong map");
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	spaces2end(t_data *data, int i)
{
	int	size;
	int	size_dif;
	int	size_max;

	size_max = ft_strlen(data->map.map[0]);
	while (data->map.map[i] != NULL)
	{
		size = ft_strlen(data->map.map[i]);
		if (size > size_max)
			size_max = size;
		i++;
	}
	i = 0;
	while (data->map.map[i] != NULL)
	{
		size = ft_strlen(data->map.map[i]);
		size_dif = size_max - size;
		while (size_dif > 0)
		{
			data->map.map[i] = ft_strjoin(data->map.map[i], " ");
			size_dif--;
		}
		i++;
	}
}

void	tab2space(t_data *data)
{
	int		i;
	int		cnt;
	char	*spaces;

	i = 0;
	spaces = ft_strdup("    ");
	while (data->map.map[i] != NULL)
	{
		cnt = 0;
		while (data->map.map[i][cnt] == '\t')
			cnt++;
		data->map.map[i] = ft_strtrim(data->map.map[i], "\t");
		while (cnt > 0)
		{
			data->map.map[i] = ft_strjoin(spaces, data->map.map[i]);
			cnt--;
		}
		i++;
	}
}

int	sides_check(t_data *data, int i, int j, char *tmp_map)
{
	while (data->map.map[0][j] != '\0')
	{
		while (data->map.map[0][j] == ' ' || data->map.map[0][j] == '\t')
			j++;
		if (data->map.map[0][j] != '1')
		{
			printf("Error\nwrong map\n");
			return (-1);
		}
		j++;
	}
	while (data->map.map[i] != NULL)
	{
		tmp_map = ft_strtrim(data->map.map[i], "\t ");
		j = ft_strlen(tmp_map);
		if (tmp_map[0] != '1' || tmp_map[j - 1] != '1')
		{
			printf("Error\nwrong map\n");
			return (-1);
		}
		i++;
	}
	return (i);
}

int	map_check(t_data *data)
{
	int		i;
	char	*tmp_map;

	tmp_map = NULL;
	i = sides_check(data, 1, 0, tmp_map);
	if (i == -1)
		return (1);
	if (sides_check2(data, i, 0))
		return (1);
	if (symb_check(data, 0, 0))
		return (1);
	tab2space(data);
	spaces2end(data, 1);
	if (closed_map(data, 1, 0))
		return (1);
	free(tmp_map);
	return (0);
}
