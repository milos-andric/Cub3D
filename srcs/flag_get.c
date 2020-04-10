/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosandric <milosandric@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:39:19 by milosand          #+#    #+#             */
/*   Updated: 2020/04/10 16:50:02 by milosandric      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    ft_getmap_flag(int fd, t_type *map)
{
int     ret;
char    *line;

map->res[0] = 0;
ft_init_t_type(map);
ret = get_next_line(fd, &line);
while (ret && ((ft_strmultichr(line, " 012SNEW")) != 1))
{
ft_getmap_values(line, map);
ret = get_next_line(fd, &line);
}
ft_check_struct(map);
}

void    ft_getmap_values(char *line, t_type *map)
{
int res;

if (!(res = ft_strncmp(line, "R ", 2)))
ft_flag_res(line + 2, map->res);
else if (!(ft_strncmp(line, "NO ", 3)))
ft_flag_str(line + 3, &map->no);
else if (!(ft_strncmp(line, "SO ", 3)))
ft_flag_str(line + 3, &map->so);
else if (!(ft_strncmp(line, "WE ", 3)))
ft_flag_str(line + 3, &map->we);
else if (!(ft_strncmp(line, "EA ", 3)))
ft_flag_str(line + 3, &map->ea);
else if (!(ft_strncmp(line, "S ", 2)))
ft_flag_str(line + 2, &map->s);
else if (!(ft_strncmp(line, "F ", 2)))
ft_flag_str(line + 2, &map->f);
else if (!(ft_strncmp(line, "C ", 2)))
ft_flag_str(line + 2, &map->c);
else if (line[0] != '\0')
ft_exit_message_basic("Unkown identifier(s) in setup file\n");
else{}
}

void    ft_flag_str(char *str, char **target)
{
int fd;

if (ft_ext_check(str, ".xpm"))
{
if (*target[0] != 0)
	ft_exit_message_basic("Several textures provided for one identifiers\n");
if ((fd = open(str, O_RDONLY)) == -1)
	ft_exit_message_basic("Invalid path for one of the textures\n");
*target = ft_strdup(str);
close(fd);
}
else
ft_exit_message_basic("Please provide a \'.xpm\' file.\n");
}

void    ft_flag_color(char *str, int *target)
{
int i;
char **splited;

i = 0;
if (ft_str_search(str, "0123456789,"))
ft_exit_message_basic("Illegal character in color declaration\n");
if (target[3] != 0)
ft_exit_message_basic("One of the colors is provided several time\n");
i = 0;
splited = ft_split(str, ',');
while (splited[i] != NULL)
i++;
if (i != 3)
ft_exit_message_basic("wtf is that color\n");
i = 0;
target[0] = ft_atoi(splited[0]);
target[1] = ft_atoi(splited[1]);
target[2] = ft_atoi(splited[2]);
while (i < 3)
{
if ((target[i] > 255) || (target[i] < 0))
ft_exit_message_basic("One of the colors is not formatted correctly\n");
i++;
}
target[3] = 1;
}

void    ft_flag_res(char *str, int *target)
{
int i;
char **splited;

i = 0;
if (ft_str_search(str, "0123456789 "))
ft_exit_message_basic("Illegal character in resolution\n");
if (target[2] != 0)
ft_exit_message_basic("Make up your mind about the resolution\n");
splited = ft_split(str, ' ');
while (splited[i] != NULL)
i++;
if (i != 2)
ft_exit_message_basic("Resolution not gud\n");
target[0] = ft_atoi(str);
str = ft_strchr(str, ' ');
target[1] = ft_atoi(str);
if (target[0] >= 2560)
target[0] = 2559;
if (target[1] >= 1440)
target[1] = 1439;
if (target[0] < 100)
target[0] = 100;
if (target[1] < 100)
target[1] = 100;
target[2] = 1;
}

char    *ft_str_search(char *str, char *chrs)
{
int i;
int flag;

i = 0;
flag = 0;
if (str == NULL)
return (NULL);
while (*str)
{
while (chrs[i])
{
if (*str == chrs[i])
	flag = 1;
i++;
}
if (flag == 0)
return (str);
flag = 0;
i = 0;
str++;
}
return (NULL);
}


void ft_check_struct(t_type *map)
{
if ((map->res[2] == 0) || ((map->f[3] == 0) || (map->c[3] == 0)))
ft_exit_message_basic("The setup file lacks one or more information\n");
if (map->no[0] == 0)
ft_exit_message_basic("North texture missing\n");
if (map->so[0] == 0)
ft_exit_message_basic("South texture missing\n");
if (map->ea[0] == 0)
ft_exit_message_basic("East texture missing\n");
if (map->we[0] == 0)
ft_exit_message_basic("West texture missing\n");
if (map->s[0] == 0)
ft_exit_message_basic("Sprite texture missing\n");
}

int		ft_strmultichr(char *str, char *chrlst)
{
int		i;
char	*ptr;
int		flaged;

i = 0;
ptr = NULL;
flaged = 1;
if ((ft_strlen(str) == 0) || ((str == NULL) && (chrlst == NULL)))
return 0;
while (str[i])
{
if (!(ptr = ft_strchr(chrlst, str[i])))
flaged = 0;
i++;
}
return (flaged);
}

int		ft_ext_check(char *str, char *end)
{
int len;
int count;

len = ft_strlen(str) - 1;
count = ft_strlen(end) - 1;
if (len == count)
return (0);
while ((str[len--] == end[count]) && ((count > 0) && (len > 0)))
count--;
if (count == 0)
return (1);
else
return (0);
}

void    ft_exit_message_basic(char *message)
{
ft_putstr("Error\n");
ft_putstr("\033[1;31m");
ft_putstr(message);
ft_putstr("\033[0m");
exit(1);
}

void	ft_init_t_type(t_type *map)
{
map->no = ft_calloc(1, sizeof(char));
map->so = ft_calloc(1, sizeof(char));
map->we = ft_calloc(1, sizeof(char));
map->ea = ft_calloc(1, sizeof(char));
map->s = ft_calloc(1, sizeof(char));
map->c = ft_calloc(1, sizeof(char));
map->f = ft_calloc(1, sizeof(char));
map->height = 0;
map->width = 0;
map->valid = 1;
map->res[0] = 0;
map->res[1] = 0;
map->res[2] = 0;
}
