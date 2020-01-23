/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cubed.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:29:52 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:23:00 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "../srcs/libft/libft.h"

typedef struct	m_struct
{
	char	**map;
	int		*res;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	f[3];
	char	c[3];
}				m_type;

int		ft_read_file(char *f_name, m_type map);
int		ft_ext_check(char *str, char *end);


#endif
