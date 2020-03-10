# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 14:51:00 by egarcia-          #+#    #+#              #
#    Updated: 2019/11/15 19:14:38 by egarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
		ft_toupper.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BONUS:.c=.o}

NAME	= libft.a

cc		= gcc

CFLAGS	= -Wall -Werror -Wextra -g

.c.o:	= ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all: $(NAME)

$(NAME) :
		gcc $(CFLAGS) -c $(SRCS)
		ar rc $(NAME)     ${OBJS}
		ranlib ${NAME}
		@mkdir -p temporary
		mv *.o temporary/

bonus:	
		gcc $(CFLAGS) -c $(SRCS) $(BONUS)
		ar rc $(NAME)     ${OBJS} $(BOBJS)
		ranlib ${NAME}

clean:
		/bin/rm -f ${OBJS} $(BOBJS)

fclean: clean
		/bin/rm -f $(NAME)
		rm -r temporary

re: fclean bonus

.PHONY: clean fclean
