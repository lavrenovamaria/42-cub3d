#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(ft_strlen_gnl(s1) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_gnl(char *remainder, char *buf)
{
	char	*joined;
	size_t	len;
	int		i;
	size_t	j;

	len = ft_strlen_gnl (remainder) + ft_strlen_gnl (buf) + 1;
	joined = (char *)malloc(sizeof(char) * (len));
	i = 0;
	if (remainder)
	{
		while (remainder[i] != '\0')
		{
			joined[i] = remainder[i];
			i++;
		}
		free (remainder);
		remainder = NULL;
	}
	j = 0;
	if (buf)
		while (buf[j] != '\0')
			joined[i++] = buf[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (len < 0)
		return (NULL);
	if (!s)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memmove_gnl(char *dst, char *src, size_t len)
{
	size_t	i;
	char	*best;

	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	best = (char *)malloc(sizeof(char) * (len + 1));
	if (best == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		best[i] = src[i];
		i++;
	}
	best[len] = '\0';
	if (dst != NULL)
		free(dst);
	return (best);
}
