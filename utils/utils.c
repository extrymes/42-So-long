/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:06:05 by sabras            #+#    #+#             */
/*   Updated: 2024/06/15 23:17:42 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/colors.h"

void	ft_print_error(char *error)
{
	ft_putstr(RED "Error\n");
	ft_putstr(error);
	ft_putstr("\n" RESET);
}
