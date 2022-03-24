/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:45:24 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 18:49:35 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	error_exit(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(-1);
}

void	*v_malloc(size_t size)
{
	void	*var;

	var = ft_calloc(1, size);
	if (!var)
		error_exit("malloc error");
	return (var);
}

int	overlap_error(t_data *data, int type)
{
	if (data->map.info_check[type - 1] == type)
		error_exit("overlap error");
	else
		data->map.info_check[type - 1] = type;
	return (type - 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	check_gnl(t_data *data, char *one_line)
{
	one_line = ft_strtrim(one_line, "\t ");
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
