# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 12:15:13 by anschmit          #+#    #+#              #
#    Updated: 2024/07/24 11:28:35 by anschmit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -I/home/anschmit/done/libft/includes -I/home/anschmit/minilibx-linux 

SRCS =	$(addprefix src/, main.c read_map.c check_map.c check_access.c positions.c)

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR = /home/anschmit/done/libft
MLX_DIR = /home/anschmit/minilibx-linux

all: $(NAME)

$(NAME): $(OBJS) libft minilibx
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft: 
	$(MAKE) -C $(LIBFT_DIR)

minilibx:
	$(MAKE) -C $(MLX_DIR)

clean:
		make clean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(MLX_DIR)

valgrind: $(NAME)
	valgrind -s --leak-check=full -- track-origins=yes --show-leak-kinds=all ./(NAME) 1.ber

re: fclean all