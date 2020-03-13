/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:20:30 by mandric           #+#    #+#             */
/*   Updated: 2020/03/04 15:21:41 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void    ft_exit_message(char *message, t_type *map)
{
    ft_putstr("Error\n");
    ft_putstr("\033[1;31m");
    ft_putstr(message);
    ft_putstr("\033[0m");
    map->valid = 0;
    //free(map);
    exit(1);
}

void    ft_exit_message_basic(char *message)
{
    ft_putstr("Error\n");
    ft_putstr("\033[1;31m");
    ft_putstr(message);
    ft_putstr("\033[0m");
    exit(1);
}