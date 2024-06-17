/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:16:46 by sabras            #+#    #+#             */
/*   Updated: 2024/06/17 17:44:31 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef GNL_BUFF
#  define GNL_BUFF 42
# endif
# ifndef GNL_MEM
#  define GNL_MEM 21
# endif
# include <unistd.h>
# include <stdlib.h>

// Basic functions
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);

// Get next line
char	*get_next_line(int fd);
int		ft_find_new_line(char *tab, int bytes_read);
char	*ft_create_line(char **tab, int len);
int		ft_tab_add(char **tab, char *buffer, int bytes_read);
int		ft_tab_realloc(char **tab, int size, int start);
void	ft_tab_free(char **tab);

#endif
