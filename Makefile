# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 13:40:01 by egarcia-          #+#    #+#              #
#    Updated: 2020/03/10 18:37:33 by egarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/cub3d.c srcs/key_manager.c srcs/read_map.c srcs/read_map2.c \
			srcs/raycasting.c srcs/raycast_aux.c srcs/raycast_f_s.c \
			srcs/parse_wall.c srcs/save.c srcs/utils.c srcs/read_map3.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra -I includes/
LIBS	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
LIBSMAC = -I /usr/local/include -L minilibx/  libmlx.a  -framework OpenGL \
			-framework AppKit ./libft/libft.a

NAME	= cub3D

all:		$(NAME)

$(NAME):	$(OBJS)
				gcc ${CFLAGS} ./includes/libft/libft.a -o ${NAME} ${OBJS} ${LIBS}

macbook:	$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBSMAC}

debug :		$(OBJS)
				gcc ${CFLAGS} -g ./includes/libft/libft.a -o ${NAME} ${OBJS} ${LIBS}

clean:
			$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)
