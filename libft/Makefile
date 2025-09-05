# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 17:10:22 by vinpache          #+#    #+#              #
#    Updated: 2025/09/05 17:11:06 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar rcs

# ATUALIZADO: Apenas as fontes necessárias para o push_swap
SRC	=	ft_atol.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isdigit.c	\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_split.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
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

