/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:49:39 by dwillett          #+#    #+#             */
/*   Updated: 2020/11/17 20:26:19 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fill_the_line(char *r, int i, int *f, char **line)
{
	if (*f == 0)
	{
		if (!(*line = ft_strdup_modified(r, i, f)))
		{
			free(r);
			return (-1);
		}
	}
	else
	{
		if (!(*line = ft_strjoin_modified(*line, r, i)))
		{
			free(r);
			return (-1);
		}
	}
	return (1);
}

int	ft_tmp_fate(char **tmp, char **line, int *f)
{
	if (*f == -1)
	{
		if (!(*line = ft_strdup_modified(*tmp, ft_search(*tmp), f)))
		{
			free(tmp);
			return (-1);
		}
		if (ft_search(*tmp) != -1)
		{
			if (!(*tmp = ft_cpy(*tmp, ft_search(*tmp) + 1, f)))
				return (-1);
			return (1);
		}
		free(*tmp);
	}
	return (0);
}

int	ft_read(int fd, char **res, char **line, int *f)
{
	int	i;

	i = read(fd, *res, BUFFER_SIZE);
	if (i == 0 || i == -1)
	{
		free(*res);
		if (*f == 0)
		{
			if ((!(*line = ft_strdup_modified("", 0, f))) || i == -1)
			{
				*f = 0;
				return (-1);
			}
		}
		*f = 0;
		return (0);
	}
	*(*res + i) = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*res;
	int			i;
	static int	flag;

	if (BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if ((i = ft_tmp_fate(&tmp, line, &flag)) != 0)
		return (i);
	if (!(res = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (((i = ft_read(fd, &res, line, &flag))) != 1)
		return (i);
	i = ft_search(res);
	if (ft_fill_the_line(res, i, &flag, line) == -1)
		return (-1);
	if (i == -1)
	{
		free(res);
		return (get_next_line(fd, line));
	}
	if (!(tmp = ft_cpy(res, i + 1, &flag)))
		return (-1);
	return (1);
}
