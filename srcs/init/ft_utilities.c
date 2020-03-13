/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:09:45 by mandric           #+#    #+#             */
/*   Updated: 2020/03/12 15:02:49 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cubed.h"

double	ft_corct_dist(t_mega *state, double dist, double angle)
{
	state->map->width = state->map->width;
	angle = ft_regulate((angle));
	return (dist * (cos(M_PI * angle / 180.0)));
}

char	*ft_rm_char(char *str, char chr)
{
	int     diff;
	int     num;
	int     i;
	char    *res;

	i = 0;
	num = 0;
	diff = ft_strlen(str) - ft_count_char(str, ' ');
	if (!(res = malloc(sizeof(char) * (diff + 1))))
		return (NULL);
	res[diff] = 0;
	while (str[i] && (num < diff))
	{
		if (str[i] != chr)
		{
			res[num] = str[i];
			num++;
		}
		i++;
	}
	//free(str);
	return (res);
}

int		ft_count_char(char *str, char chr)
{
	int i;
	double count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == chr)
			count++;
		i++;
	}
	return (count);
}

void	ft_print_map(t_type *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			ft_putchar_fd(map->map[j][i] + 48, 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
		j = 0;
	}
}

char	*ft_strmultichr(char *str, char *chrlst)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (str[i])
	{
		if (!(ptr = ft_strchr(chrlst, str[i])))
			return (ptr);
		i++;
	}
	return (ptr);
}

void	ft_print_struct(t_type *map)
{
	ft_putstr("height : ");
	ft_putnbr_fd(map->height, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr("width : ");
	ft_putnbr_fd(map->width, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr("valid : ");
	ft_putnbr_fd(map->valid, 1);
	ft_putchar_fd('\n', 1);
	dprintf(1, "res : %d, %d\n", map->res[0], map->res[1]);
	dprintf(1, "North : %s\n", map->no);
	dprintf(1, "South : %s\n", map->so);
	dprintf(1, "East : %s\n", map->ea);
	dprintf(1, "West : %s\n", map->we);
	dprintf(1, "Sprite : %s\n", map->s);
	dprintf(1, "floor : %d, %d, %d\n", map->f[0], map->f[1], map->f[2]);
	dprintf(1, "res : %d, %d, %d\n", map->c[0], map->c[1], map->c[2]);
}

void	ft_init_t_type(t_type *map)
{
	map->no = ft_calloc(1, sizeof(char));
	map->so = ft_calloc(1, sizeof(char));
	map->we = ft_calloc(1, sizeof(char));
	map->ea = ft_calloc(1, sizeof(char));
	map->s = ft_calloc(1, sizeof(char));
	map->height = 0;
	map->width = 0;
	map->valid = 1;
	map->f[0] = 0;
	map->f[1] = 0;
	map->f[2] = 0;
	map->f[3] = 0;
	map->c[0] = 0;
	map->c[1] = 0;
	map->c[2] = 0;
	map->c[3] = 0;
	map->res[0] = 0;
	map->res[1] = 0;
	map->res[2] = 0;
}