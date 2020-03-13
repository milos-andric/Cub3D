/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <mandric@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:55:07 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 18:25:24 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int		ft_read_file(char *f_name, t_type *map)
{
	int fd;

	ft_init_t_type(map);
	ft_getmap_map(f_name, map);
	if ((fd = open(f_name, O_RDONLY)) == -1)
		return (-1);
	ft_getmap_flag(fd, map);
	ft_check_map(map);
	close (fd);
	ft_print_struct(map);
	//ft_print_map(map);
	return (0);
}

int		**ft_alloc_tab(int height, int width)
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = malloc(sizeof(int *) * width)))
		return (NULL);
	while (i < width)
	{
		if (!(tab[i] = malloc(sizeof(int) * height)))
			return (NULL);
		i++;
	}
	return (tab);
}