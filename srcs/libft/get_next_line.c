/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <mandric@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 11:36:35 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:20:23 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_getlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-i);
}

void		ft_manager(char *buffer, int len, char **line, int *red)
{
	char *temp;
	char *btemp;

	if (len < 0)
	{
		temp = ft_strjoin_gnl(*line, buffer);
		free(*line);
		*line = temp;
	}
	else
	{
		temp = ft_substr(buffer, 0, len);
		btemp = ft_strjoin_gnl(*line, temp);
		free(temp);
		free(*line);
		*line = btemp;
		btemp = ft_substr(buffer, len + 1, ft_strlen(buffer) - len + 1);
		ft_strlcpy_gnl(buffer, btemp, ft_strlen(btemp));
		free(btemp);
		if (*red)
			*red = *red - (len + 1);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		buffer[80 + 1] = {0};
	static int		red;
	int				len;
	int				flag;

	flag = 1;
	*line = (char *)ft_calloc(1, sizeof(char));
	if (!ft_strlen(buffer) && !(red = read(fd, buffer, 80)))
		flag = 0;
	buffer[red] = 0;
	len = ft_getlen(buffer);
	while ((len < 0) && (red > 0))
	{
		ft_manager(buffer, len, line, &red);
		if ((red = read(fd, buffer, 80)) == 0)
			flag = 0;
		buffer[red] = 0;
		len = ft_getlen(buffer);
	}
	if ((len >= 0) && (red > 0))
	{
		ft_manager(buffer, len, line, &red);
		return (flag);
	}
	return (red == -1 ? -1 : 0);
}
