/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy_gnl.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 12:46:38 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 12:49:48 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	int i;

	i = -1;
	while (src[++i] && (--size + 1))
		dst[i] = src[i];
	dst[i] = '\0';
	while (src[i])
		i++;
	return ((size_t)i);
}
