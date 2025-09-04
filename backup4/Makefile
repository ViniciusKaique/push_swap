# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 18:29:23 by aaybaz            #+#    #+#              #
#    Updated: 2025/09/04 19:26:05 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# --- Libft ---
LIBFT_DIR   = ./libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
# CORREÇÃO 1: Corrigido o erro de digitação de $(LIB--DIR) para $(LIBFT_DIR)
LIBFT_INC   = -I $(LIBFT_DIR)
LIBFT_LNK   = -L $(LIBFT_DIR) -lft

# --- Push_swap Sources ---
SRCS        = push_swap.c \
              src/do_pp.c \
              src/do_rr.c \
              src/do_rrr.c \
              src/do_ss.c \
              src/utils_1.c \
              src/utils_2.c \
              src/utils_3.c \
              src/utils_for_sort.c \
              sort/sort_max.c \
              sort/sort_min.c \
              sort/sort.c
# CORREÇÃO 2: Trocado 'src/parser.c' por 'src/utils_3.c', que é o arquivo que de fato criamos.

OBJS        = $(SRCS:.c=.o)

# --- Rules ---
all: $(NAME)

# CORREÇÃO 3: Adicionado $(LIBFT_INC) para que o compilador encontre "libft/libft.h".
$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(OBJS) $(LIBFT_LNK) -o $(NAME)

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
