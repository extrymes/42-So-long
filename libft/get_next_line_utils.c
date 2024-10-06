/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:22:59 by sabras            #+#    #+#             */
/*   Updated: 2024/10/06 02:06:20 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_new_line(char *tab, int bytes_read)
{
	int		i;

	if (!tab && bytes_read == 0)
		return (0);
	if (!tab)
		return (-1);
	i = 0;
	while (tab[i] && tab[i] != '\n')
		i++;
	if (tab[i] == '\n')
		return (i + 1);
	if (bytes_read == 0 || bytes_read < GNL_BUFF)
	{
		i = 0;
		while (tab[i])
			i++;
		return (i);
	}
	return (-1);
}

char	*ft_create_line(char **tab, int len)
{
	char	*line;
	int		i;

	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (ft_tab_free(tab), NULL);
	i = -1;
	while (++i < len)
		line[i] = (*tab)[i];
	line[i] = '\0';
	i = 0;
	while ((*tab)[i])
		i++;
	if (i == len)
		ft_tab_free(tab);
	if (!ft_tab_realloc(tab, (((i - len + 1) / GNL_MEM) + 1) * GNL_MEM, len))
		return (free(line), NULL);
	return (line);
}

int	ft_tab_add(char **tab, char *buffer, int bytes_read)
{
	int		i;
	int		j;
	int		size;

	if (bytes_read == 0)
		return (free(buffer), 1);
	i = 0;
	while (*tab && (*tab)[i])
		i++;
	size = (i + bytes_read + 1) / GNL_MEM;
	if (!*tab || (i + 1) / GNL_MEM < size)
	{
		if (!ft_tab_realloc(tab, (size + 1) * GNL_MEM, 0))
			return (0);
	}
	j = 0;
	while (j < bytes_read)
		(*tab)[i++] = buffer[j++];
	(*tab)[i] = '\0';
	return (free(buffer), 1);
}

int	ft_tab_realloc(char **tab, int size, int start)
{
	char	*tmp;
	int		i;

	tmp = malloc(size * sizeof(char));
	if (!tmp)
		return (0);
	i = 0;
	while (*tab && (*tab)[i + start])
	{
		tmp[i] = (*tab)[i + start];
		i++;
	}
	tmp[i] = '\0';
	ft_tab_free(tab);
	*tab = malloc(size * sizeof(char));
	if (!*tab)
		return (free(tmp), 0);
	i = 0;
	while (tmp[i])
	{
		(*tab)[i] = tmp[i];
		i++;
	}
	(*tab)[i] = '\0';
	return (free(tmp), 1);
}

void	ft_tab_free(char **tab)
{
	if (*tab)
		free(*tab);
	*tab = NULL;
}
