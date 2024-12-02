# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 12:15:13 by anschmit          #+#    #+#              #
#    Updated: 2024/12/02 16:44:17 by anschmit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directory structure
LONG_DIR = .
LIBFT_DIR = $(LONG_DIR)/libft
MLX_DIR = $(LONG_DIR)/minilibx-linux

# Executable name
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(MLX_DIR)

# Source files
SRCS = $(addprefix src/, main.c read_map.c check_map.c check_access.c positions.c image.c movement.c end_game.c)
OBJS = $(SRCS:%.c=%.o)

# Main rule
all: $(NAME)

# Rule to make libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Rule to make minilibx
$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

# Main compilation rule
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Compile individual object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Run with Valgrind
valgrind: $(NAME)
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) 1.ber

# Phony targets
.PHONY: all clean fclean re valgrind