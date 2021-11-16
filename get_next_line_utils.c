#include "get_next_line.h"

int		ft_search(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == '\n')
		{
			return (i - 1);
		}
	}
	return (-1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup_modified(char *s1, int end, int *f)
{
	char	*res;
	int		i;

	i = 0;
	if (end == -1)
		res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	else
		res = (char*)malloc(sizeof(char) * (end + 1));
	if (res)
	{
		while (s1[i] != '\0' && (end == -1 || i < end))
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
		*f = 1;
		return (res);
	}
	return (NULL);
}

char	*ft_strjoin_modified(char *s1, char *s2, int end)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (end == -1)
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
	else
		i = ft_strlen(s1) + end + 1;
	j = 0;
	if (!(res = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && (end == -1 || j < end))
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_cpy(char *src, int start, int *f)
{
	int		i;
	char	*res;

	i = 0;
	*f = -1;
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(src) - start + 1))))
	{
		free(src);
		*f = 0;
		return (NULL);
	}
	while (src[start] != '\0')
	{
		res[i++] = src[start++];
	}
	free(src);
	res[i] = '\0';
	return (res);
}
