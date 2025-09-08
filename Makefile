# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 13:14:52 by vinpache          #+#    #+#              #
#    Updated: 2025/09/08 13:15:33 by vinpache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		= \033[0m
GREEN_BOLD	= \033[1;32m
YELLOW_BOLD	= \033[1;33m
RED_BOLD	= \033[1;31m

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
              src/sort_utils.c \
              src/sort.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(OBJS) $(LIBFT_LNK) -o $(NAME)
	@echo "$(GREEN_BOLD)✅ Push_swap compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@
	@echo "$(YELLOW_BOLD)Compiling:$(RESET) $<"

$(LIBFT_A):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@rm -f $(OBJS)
	@echo "$(RED_BOLD)🧼 Push_swap objects removed!$(RESET)"

fclean:
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "$(RED_BOLD)🧼 Push_swap project fully cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus