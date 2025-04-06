# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 11:55:49 by jrichir           #+#    #+#              #
#    Updated: 2025/04/03 12:41:45 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRCS =	./srcs/main.c \
		./srcs/utils.c \
		./srcs/get_lines.c \
		./srcs/parsing.c \
		./srcs/checking.c \
		./srcs/check_map.c \
		./srcs/load_tx.c \
		./srcs/render.c \
		./srcs/raycast.c \
		./srcs/raycast_utils.c \
		./srcs/draw.c \
		./srcs/render_utils.c \
		./srcs/key_press_release.c \
		./srcs/move.c \
		./srcs/rotate.c

BNS =	./bonus/check_map_bonus.c \
		./bonus/checking_bonus.c \
		./bonus/doors_bonus.c \
		./bonus/draw_bonus.c \
		./bonus/get_lines_bonus.c \
		./bonus/key_press_release_bonus.c \
		./bonus/load_tx_bonus.c \
		./bonus/main_bonus.c \
		./bonus/mini_map_bonus.c \
		./bonus/move_bonus.c \
		./bonus/parsing_bonus.c \
		./bonus/raycast_bonus.c \
		./bonus/raycast_utils_bonus.c \
		./bonus/render_bonus.c \
		./bonus/render_utils_bonus.c \
		./bonus/rotate_bonus.c \
		./bonus/utils_bonus.c

HEADER = cube.h

HEADER_BNS = cube_bonus.h

OBJECTS = $(SRCS:%.c=%.o)

OBJ_BNS = $(BNS:%.c=%.o)

CFLAGS = -g -Wall -Wextra -Werror

CC = cc

RM = rm -f

MAKE_LIBFT = make -s -C ./libft

MAKE_MLX = make -s -C ./minilibx-linux

LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "\033[K\033[0;34mFiles compiled.\033[0m\n"
	@printf "\033[0;35mCompiling the libft...\033[0m\r"

	@$(MAKE_LIBFT)
	@printf "\033[K\033[0;34mLibft compiled.\033[0m\n"
	@printf "\033[0;35mCompiling the minilibx...\033[0m\r"

	@${MAKE_MLX} > /dev/null 2>&1
	@printf "\033[K\033[0;34mMinilibx compiled.\033[0m\n"

	@$(CC) $(CFLAGS) ${OBJECTS} ${LIBFT} ${MLX} -Lminilibx-linux -lmlx_Linux -lm -lX11 -lXext -I ${HEADER} -o ${NAME}
	@printf "\033[0;32mThe binary '$(NAME)' is ready.\033[0m\n"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BNS)
	@printf "\033[K\033[0;34mFiles compiled.\033[0m\n"
	@printf "\033[0;35mCompiling the libft...\033[0m\r"

	@$(MAKE_LIBFT)
	@printf "\033[K\033[0;34mLibft compiled.\033[0m\n"
	@printf "\033[0;35mCompiling the minilibx...\033[0m\r"

	@${MAKE_MLX} > /dev/null 2>&1
	@printf "\033[K\033[0;34mMinilibx compiled.\033[0m\n"

	@$(CC) $(CFLAGS) ${OBJ_BNS} ${LIBFT} ${MLX} -Lminilibx-linux -lmlx_Linux -lm -lX11 -lXext -I ${HEADER_BNS} -o ${NAME_BONUS}
	@printf "\033[0;32mThe binary '$(NAME_BONUS)' is ready.\033[0m\n"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@printf "\033[K\033[0;35mCompiling the files... : \033[0;33m%s\r" "$<"

clean:
	@$(MAKE_LIBFT) clean
	@${MAKE_MLX} clean > /dev/null 2>&1
	@$(RM) $(OBJECTS) $(OBJ_BNS)
	@printf "\033[0;31mAll objects files removed.\033[0m\n"

fclean: clean
	@$(MAKE_LIBFT) fclean
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "\033[0;31mBinary destroyed.\n\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re
