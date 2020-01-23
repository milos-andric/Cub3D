/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_gnl.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 12:47:13 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 12:47:59 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (!s1 && !s2)
		return (ptr = ft_calloc(1, 1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = (char *)(malloc((len1 + len2 + 1) * sizeof(char)))))
		return (NULL);
	if (s1)
		ft_strlcpy_gnl(ptr, s1, len1);
	if (s2)
		ft_strlcpy_gnl(&(ptr[len1]), s2, len2);
	return (ptr);
}
