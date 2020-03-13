# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 16:37:16 by mandric           #+#    #+#              #
#    Updated: 2020/03/06 15:31:00 by mandric          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


#	Makefile	#

NAME		= cubed.a

EXEC		= cub3D

SRCS		= 	srcs/init/ft_cubed.c
SRCS		+= 	srcs/init/parsing.c
SRCS		+= 	srcs/init/ft_getmap.c
SRCS		+= 	srcs/init/ft_check_map.c
SRCS		+= 	srcs/init/ft_utilities.c
SRCS		+= 	srcs/init/ft_flags.c
SRCS		+= 	srcs/init/ft_error.c

SRCS		+= 	srcs/graph/ft_util.c
SRCS		+= 	srcs/graph/ft_draw_line.c
SRCS		+= 	srcs/graph/ft_draw_square.c
SRCS		+= 	srcs/graph/ft_mlx.c
SRCS		+= 	srcs/graph/ft_porcelain.c
SRCS		+= 	srcs/graph/ft_raycast.c
SRCS		+= 	srcs/graph/ft_texture.c

OBJS	= 	${SRCS:.c=.o}

OBJS_BNS	= 	${SRCS_BNS:.c=.o}

CC		=	gcc  

CFLAGS	= 	-Wall -Werror -Wextra -fsanitize=address -g3

MAKE	=	make

INCLUDES_PATH = ./includes/

LIBFT_PATH	= ./srcs/libft/

INCLUDES	= 	$(LIBFT_PATH)libft.h		\
				$(INCLUDES_PATH)cubed.h

$(NAME)	:	$(OBJS) $(INCLUDES)
	$(MAKE) -C $(LIBFT_PATH) bonus
	cp $(LIBFT_PATH)libft.a $(NAME)
	cp minilibx/libmlx.a $(NAME)
	ar rc $(NAME) $(OBJS)
	$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT_PATH)libft.a -framework OpenGL -framework AppKit -o $(EXEC)

all		:	 $(NAME) $(INCLUDES)

bonus	:	$(OBJS) $(OBJS_BNS) $(INCLUDES)
	ar rc $(NAME) $(OBJS) $(OBJS_BNS)

$(OBJS) : $(INCLUDES)

$(OBJS_BNS) : $(INCLUDES)

clean	:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS) $(OBJS_BNS)

fclean	:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re 		:	fclean all

comp	:
	clear
	$(CC) $(CFLAGS) main.c $(NAME)

launch	: all comp
	./a.out test.cub
