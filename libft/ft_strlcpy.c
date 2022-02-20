/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:46:03 by wrickard          #+#    #+#             */
/*   Updated: 2021/10/11 20:37:34 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
