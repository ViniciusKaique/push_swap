# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 11:09:32 by vinpache          #+#    #+#              #
#    Updated: 2025/09/06 11:09:44 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar rcs

SRC	=	ft_atol.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isdigit.c	\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_split.c		\
		ft_strdup.c		\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_substr.c

OBJS = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus

