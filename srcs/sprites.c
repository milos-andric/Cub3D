/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosandric <milosandric@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:02:21 by siferrar          #+#    #+#             */
/*   Updated: 2020/04/18 15:40:28 by milosandric      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_sprite   *init_sprite(t_map *m, t_fpoint pos, int type)
{
	t_sprite	*s;
	t_brain		*b;

	dprintf(1, "Init Sprite\n");
	b = (t_brain *)m->brain;
	if (!(s = malloc(sizeof(t_sprite))))
		return (NULL);
	s->pos = pos;
	s->pos.x = pos.x * m->bloc_size;
	s->pos.y = pos.y * m->bloc_size;
	s->model = NULL;
	s->on_screen = 0;
	init_texture(b, "./assets/sprites/barrel.xpm", &s->model);
	s->type = 2;
	s->next = NULL;
	return (s);
}

int		compare(t_fpoint p1, t_fpoint p2, int range)
{
	if (p1.x >= p2.x - range && p1.x <= p2.x + range && p1.y >= p2.y - range && p1.y <= p2.y + range)
		return (1);
	else
		return (0);
}

t_sprite *get_sprite(t_map *m, t_fpoint p)
{
	t_sprite **ptr;
	t_fpoint in_grid;
	t_sprite *sprites;

	//dprintf(1, "Getting sprite\n");

	sprites = (t_sprite *)m->sprites;
	ptr = &sprites;
	while (*ptr != NULL)
	{
		//dprintf(1, "Check Sprites x:%f y:%f  VS x:%f y:%f \n", (*ptr)->pos.x, (*ptr)->pos.y, p.x, p.y);
		if (compare((*ptr)->pos, p, m->bloc_size + 2))
		{
			//dprintf(1, "Sprite found\n");
			return (*ptr);
		}
		ptr = &((*ptr)->next);
	}
	//dprintf(1, RED"Sprite NOT found\n"RST);

	return (NULL);
}

void	add_spr_to_list(t_spr_list *s_list, t_sprite *s)
{
	t_sprite **ret;
	int i;

	i = 0;
	dprintf(1, YELO"Add spr to list\n");
	disp_sprite(s);
	ret = malloc((s_list->length + 1) * sizeof(t_sprite *));
	if (s_list->list != NULL)
		while (i < s_list->length)
		{
			ret[i] = s_list->list[i];
			i++;
		}
	ret[i] = s;
	free(s_list->list);
	s_list->list = ret;
	s_list->length++;
	dprintf(1, GRN"Add spr to list OK\n"RST);
}

void    swap_sprite(t_spr_list *lst_sprt, int num1, int num2)
{
	if((num1 < lst_sprt->length) && (num2 < lst_sprt->length) && (num1 != num2))
	{
		t_sprite temp;
		t_sprite *spr_a;
		t_sprite *spr_b;

		spr_a = lst_sprt->list[num1];
		spr_b = lst_sprt->list[num2];
		temp.dist = spr_a->dist;
		temp.pos = spr_a->pos;
		spr_a->dist = spr_b->dist;
		spr_a->pos = spr_b->pos;
		spr_b->dist = temp.dist;
		spr_b->pos = temp.pos;
	}
}


void	disp_sprites(t_spr_list *s_list)
{
	int			i;
	t_sprite	*s;
	i = 0;
	ft_putstr(PINK);
	if (s_list->list != NULL)
	{
		dprintf(1, "%d sprites in list\n", s_list->length);
		while (i < s_list->length)
		{
			disp_sprite(s_list->list[i]);
			i++;
		}
		dprintf(1, "End of loop\n");
	} else {
		dprintf(1, "No sprites in list\n");
	}
	ft_putstr(RST);
}

void	disp_sprite(t_sprite *s)
{
	dprintf(1, "Sprite of type %d\n", s->type);
	disp_point(&(s->pos));
}


void	draw_sprite(void *brain, t_sprite *s, float col)
{
	t_brain		*b;
	t_fpoint	s_size;
	t_fpoint	s_dist;
	t_fpoint	ratio;
	double		dist;
	double		angle;
	double		start_y;
	int			color;
	int			y;
	int			texture_col;

	b = (t_brain *)brain;
	/*
	dist = calc_dist(*b->player->pos, s->pos);

	s_dist.x = s->pos.x - b->player->pos->x;
	s_dist.y = s->pos.y - b->player->pos->y;
	
	s_size.x = s->model->width * b->ctx->width / dist;
	s_size.y = s->model->height * b->ctx->height / dist;

	angle = atan2(s_dist.y, s_dist.x);
	angle = b->player->angle - angle;
	*/
	dist = s->dist;
	s_size.x = 72;
	s_size.y = 72;
	start_y = (b->ctx->height / 2) * (1 + (1 / dist)) - s_size.y;
	//start_y = 1;
	ratio.x = s_size.x / b->map->bloc_size;
	ratio.y = s_size.y / b->map->bloc_size;

	while (y < s_size.y)
	{
		color = pixel_get(s->model, col * ratio.x, y * ratio.y);

		pixel_put(col, y, color, b->map->frame);
		y++;
	}
}

void    sort_sprites(t_fpoint *pos, t_spr_list *lst_sprt)
{
	float dist1;
	float dist2;
	int i;
	int j;

	i = 0;
	dprintf(1, CYAN"Order Sprites\n"RST);
	while (i < lst_sprt->length)
	{
		j = i;
		while (j < lst_sprt->length)
		{
			dist1 = calc_dist(*pos, lst_sprt->list[i]->pos);
			dist2 = calc_dist(*pos, lst_sprt->list[j]->pos);
			lst_sprt->list[i]->dist = dist1;
			lst_sprt->list[j]->dist = dist2;
			dprintf(1, "%f vs %f\n", dist1, dist2);
			if (dist1 > dist2)
			{
				dprintf(1, "Swap [%d] and [%d]\n", i, j);
				//disp_sprite(lst_sprt->list[i]);
				//disp_sprite(lst_sprt->list[j]);
				swap_sprite(lst_sprt, i, j);
			}
			j++;
		}
		i++;
	}
	dprintf(1, CYAN"Order Sprites OK\n"RST);
}

float	deg_sprite(t_player *ply, t_spr_list *spr)
{
	float angle;
	t_fpoint s_dist;
	int i;
	
	i = 0;
	while(i < spr->length)
	{
		s_dist.x = spr->list[i]->pos.x - ply->pos->x;
		s_dist.y = spr->list[i]->pos.y - ply->pos->y;
		angle = atan2(s_dist.y, s_dist.x);
		angle = to_360(ply->angle - angle);	
		dprintf(1, "%f\t%f\n", ply->pos->x, ply->pos->y);
		dprintf(1, "angle : %f\n", ft_indeg(angle));
		spr->list[i]->deg = ft_indeg(angle);
		if((spr->list[i]->deg > (360 - ft_indeg(ply->cam->fov / 2))) 
			|| (spr->list[i]->deg < ft_indeg(ply->cam->fov / 2))) // a opti
			spr->list[i]->on_screen = 1;
		else
			spr->list[i]->on_screen = 0;
		dprintf(1, "on_scr : %d\n", spr->list[i]->on_screen);
		i++;
	}
}

void	update_sprite(t_brain *b)
{
	int i;
	
	i = 0;
	sort_sprites(b->player->pos, b->map->sprites);
	deg_sprite(b->player, b->map->sprites);
	/*while(i < b->map->sprites->length)
	{
		if(b->map->sprites->list[i]->on_screen)
			b->ctx->rect();
		i++;
	}*/
}