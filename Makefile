# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 11:09:50 by vinpache          #+#    #+#              #
#    Updated: 2025/09/06 11:13:44 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
LIBFT_INC   = -I $(LIBFT_DIR)
LIBFT_LNK   = -L $(LIBFT_DIR) -lft

SRCS        = push_swap.c \
              src/swap.c \
              src/push.c \
              src/rotate.c \
              src/rotate_rev.c \
              src/validation.c \
              src/stack_utils.c \
              src/array_utils.c \
              src/sort_utils.c \
              src/sort.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(OBJS) $(LIBFT_LNK) -o $(NAME)
	@echo "Push_swap compiled ✅"
    
$(LIBFT_A):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	@echo "Push_swap objects cleaned ✅"

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS)
	rm -f $(NAME)
	@echo "Push_swap cleaned ✅"

re: fclean all

.PHONY: all clean fclean re

