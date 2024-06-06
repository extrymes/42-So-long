/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:19:31 by sabras            #+#    #+#             */
/*   Updated: 2024/06/06 12:18:19 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	static char		*tab;
	char			*buffer;
	int				bytes_read;
	int				len;

	if (GNL_BUFF < 1)
		return (NULL);
	len = ft_find_new_line(tab, GNL_BUFF);
	while (len == -1)
	{
		buffer = malloc((GNL_BUFF) * sizeof(char));
		if (!buffer)
			return (ft_tab_free(&tab), NULL);
		bytes_read = read(fd, buffer, GNL_BUFF);
		if (bytes_read == -1 || !ft_tab_add(&tab, buffer, bytes_read))
			return (ft_tab_free(&tab), free(buffer), NULL);
		len = ft_find_new_line(tab, bytes_read);
		if (len == 0)
			return (ft_tab_free(&tab), NULL);
	}
	return (ft_create_line(&tab, len));
}
