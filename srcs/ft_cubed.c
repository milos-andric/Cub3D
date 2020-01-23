/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cubed.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:20:41 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:21:37 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cubed.h"

int		ft_read_file(char *f_name) //m_type map)
{
	int 	fd;
	int		r_val;
	char	*res_tab;
	int		height;

	r_val = 1;
	if (ft_ext_check(f_name, ".cub"))
	{
		if ((fd = open(f_name, O_RDONLY)) == -1)
			return (-1);
		while (r_val)
		{
			r_val = get_next_line(fd, &res_tab);
			printf("%d :%s\n", r_val, res_tab);
			height++;
		}
		close (fd);
		return (0);
	}
	else
		return (-1);
}
