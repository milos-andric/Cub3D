/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:55:07 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:22:49 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cubed.h"

int		ft_ext_check(char *str, char *end)
{
	int len;
	int count;

	len = ft_strlen(str);
	count = ft_strlen(end);
	if (len == count)
		return (0);
	while ((str[len--] == end[count]) && ((count >= 0) && (len >= 0)))
		count--;
	if (count == -1)
		return (1);
	else
		return (0);
}
/*
int		ft_getmap_specs(int fd, m_type *map)
{
	int ret;

	ret = 1;
	while(ret)
	{
		
	}
}
*/
