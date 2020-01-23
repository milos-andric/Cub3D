/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:20:16 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:23:09 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/cubed.h"

int	main(int argc, char **argv)
{
	m_type map;

	if (argc != 2)
	{
		ft_putstr("OOOOOPSIEE");
	}
	else
	{
		ft_read_file(argv[1], &map);
	}
	return (0);
}
