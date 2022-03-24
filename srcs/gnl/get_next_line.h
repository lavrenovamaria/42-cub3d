/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrickard <wrickard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:02:07 by wrickard          #+#    #+#             */
/*   Updated: 2022/03/21 19:02:19 by wrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 256

int			get_next_line(int fd, char **line);
size_t		ft_strlen_gnl(char *s);
int			ft_find_nl(char *str);
char		*ft_strdup_gnl(char *s1);
char		*ft_strjoin_gnl(char *remainder, char *buf);
char		*ft_substr_gnl(char *s, int start, int len);
void		*ft_memmove_gnl(char *dst, char *src, size_t len);
int			ft_split_line(char **str, char **line, int index);
int			ft_return_line(char **str, char **line, int ret, int index);

#endif
