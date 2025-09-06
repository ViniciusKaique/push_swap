# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 18:29:23 by aaybaz            #+#    #+#              #
#    Updated: 2025/09/06 10:26:32 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# --- Libft ---
LIBFT_DIR   = ./libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
LIBFT_INC   = -I $(LIBFT_DIR)
LIBFT_LNK   = -L $(LIBFT_DIR) -lft

# --- Push_swap Sources ---
# ATUALIZADO: Lista de fontes com a nova organização de arquivos semântica.
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

# --- Rules ---
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

