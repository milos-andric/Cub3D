/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <mandric@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 10:28:24 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/18 18:37:35 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void    ft_getmap_flag(int fd, t_type *map)
{
    int     ret;
	char    *line;

    map->res[0] = 0;
	ret = get_next_line(fd, &line);
	while (ret && ((line[0] != '0') && (line[0] != '1')))
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
        ft_flag_color(line + 2, map->f);
    else if (!(ft_strncmp(line, "C ", 2)))
        ft_flag_color(line + 2, map->c);
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
