/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:29:52 by mandric           #+#    #+#             */
/*   Updated: 2020/03/12 15:05:22 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> //OUPSIIII
# include "../srcs/libft/libft.h"
#include "../minilibx/mlx.h"

typedef struct	s_struct
{
	int			**map;
	int			height;
	int			width;
	int			valid;
	int			res[3];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f[4];
	int			c[4];
}				t_type;

typedef struct	s_player {
	double		fov;
	double		degree;
	double		std_size;
	double		posX;
	double		posY;
}				t_player;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_texture {
	int			*textures[4];
	int			width[4];
	int			height[4];
}				t_texture;

typedef struct	s_mega
{
	t_type		*map;
	t_player	*player;
	t_data		*img;
	t_texture	*text;
	int			rc_v_x;
	int			rc_v_y;
	int			rc_h_x;
	int			rc_h_y;
	double		rc_ya;
	double		rc_xa;
	void		*mlx;
	void		*mlx_win;
}				t_mega;

/*
**------------------------- CHECKING FUNCTIONS ----------------------------
*/

int		ft_ext_check(char *str, char *end);
void	ft_check_map(t_type *map);
void	ft_check_borders(t_type *map);
void	ft_check_char(t_type *map);
void	ft_check_begin_char(t_type *map);
int		ft_is_good_char(int var);
void	ft_check_struct(t_type *map);

/*
**------------------------- INIT FUNCTIONS ----------------------------
*/

void	ft_init_player(t_player *player, t_type *map);
void	ft_init_t_type(t_type *map);

/*
**------------------------- PRINTING FUNCTIONS ----------------------------
*/

void	ft_print_map(t_type *map);
void	ft_print_struct(t_type *map);

/*
**------------------------- ALLOCATION FUNCTIONS ----------------------------
*/

int		**ft_alloc_tab(int height, int width);

/*
**------------------------- MAP GETTER FUNCTIONS ----------------------------
*/

void	ft_getmap_map(char *f_name, t_type *map);
void	ft_getmap_dim(int fd, t_type *map);
int		ft_getmap(int fd, t_type *map);

/*
**------------------------- FLAG GETTER FUNCTIONS ----------------------------
*/

void	ft_getmap_flag(int fd, t_type *map);
void	ft_getmap_values(char *str, t_type *map);
void	ft_flag_str(char *str, char **target);
void	ft_flag_res(char *str, int *target);
void    ft_flag_color(char *str, int *target);

/*
**------------------------- PORCELAIN FUNCTIONS ----------------------------
*/

int		ft_read_file(char *f_name, t_type *map);
void	ft_draw_map(t_mega *state,int x, int y, int sqr);
void	ft_draw_player(t_mega *state);
void	ft_draw_world(t_mega *state, double distance, int column, int modulo);

/*
**----------------------------- UTILITIES -------------------------------------
*/

char	*ft_rm_char(char *str, char chr);
int		ft_count_char(char *str, char chr);
char	*ft_str_search(char *str, char *chrs);
double	ft_regulate(double angle);
double	ft_give_length(double x1, double y1, double x2, double y2);
double	ft_map_size_calc(t_mega *state, double percent);
double	ft_check_mur(t_mega *state, double x, double y);
double	ft_corct_dist(t_mega *state, double dist, double angle);
char	*ft_strmultichr(char *str, char *chrlst);

/*
**----------------------------- EXIT FUNCTIONS ------------------------------
*/

void	ft_exit_message(char *message, t_type *map);
void	ft_exit_message_basic(char *message);

/*
**----------------------------- DRAW FUNCTIONS ------------------------------
*/

void			ft_draw_line_low(t_mega *state, int x1, int y1, int x2, int y2);
void			ft_draw_line_high(t_mega *state, int x1, int y1, int x2, int y2);
double			ft_abs(double nb);
void			ft_draw_line(t_mega *state, int x1, int y1, int x2, int y2);
void			ft_draw_line_angle(t_mega *state, double angle, double distance);
void			ft_draw_r_sqr(t_mega *state, int x, int y, int width, int height);
void			ft_draw_w_sqr(t_mega *state, int x, int y, int width, int height);
void			ft_draw_b_sqr(t_mega *state, int x, int y, int width, int height);

/*
**----------------------------- MLX FUNCTIONS ------------------------------
*/

int		ft_loop(t_mega *state);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_press(int key, t_player *player);

/*
**----------------------------- RAYCAST FUNCTIONS ------------------------------
*/

void	ft_draw_line_aware_v(t_mega *state, double angle);
void	ft_draw_line_aware_h(t_mega *state, double angle);

/*
**----------------------------- TEXTURE FUNCTIONS ------------------------------
*/

void	ft_load_textures(t_mega *state);
void	ft_draw_text_sqr(t_mega *state, int x, int y, int texture);
void	ft_texture_line(t_mega *state, int y1, int y2, int modulo, int column, int texture);
#endif