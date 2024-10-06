/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:06:05 by sabras            #+#    #+#             */
/*   Updated: 2024/10/06 02:07:35 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_you_win(void)
{
	ft_putstr(GREEN "\n\
░█──░█ ░█▀▀▀█ ░█─░█  ░█──░█ ▀█▀ ░█▄─░█ █\n\
░█▄▄▄█ ░█──░█ ░█─░█  ░█░█░█ ░█─ ░█░█░█ ▀\n\
──░█── ░█▄▄▄█ ─▀▄▄▀  ░█▄▀▄█ ▄█▄ ░█──▀█ ▄\n\n" RESET);
}

void	ft_print_you_died(void)
{
	ft_putstr(RED "\n\
░█──░█ █▀▀█ █──█  █▀▀▄ ─▀─ █▀▀ █▀▀▄ █\n\
░█▄▄▄█ █──█ █──█  █──█ ▀█▀ █▀▀ █──█ ▀\n\
──░█── ▀▀▀▀ ─▀▀▀  ▀▀▀─ ▀▀▀ ▀▀▀ ▀▀▀─ ▄\n\n" RESET);
}

void	ft_print_error(char *error)
{
	ft_putstr(RED "Error\n");
	ft_putstr(error);
	ft_putstr("\n" RESET);
}
