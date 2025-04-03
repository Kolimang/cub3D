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
SRCS =	./srcs/main_bonus.c \
		./srcs/utils_bonus.c \
		./srcs/parsing_bonus.c \
		./srcs/checking_bonus.c \
		./srcs/check_map_bonus.c \
		./srcs/load_tx_bonus.c \
		./srcs/render_bonus.c \
		./srcs/raycast_bonus.c \
		./srcs/raycast_utils_bonus.c \
		./srcs/draw_bonus.c \
		./srcs/render_utils_bonus.c \
		./srcs/mini_map_bonus.c \
		./srcs/key_press_release_bonus.c \
		./srcs/move_bonus.c \
		./srcs/rotate_bonus.c \
		./srcs/doors_bonus.c

HEADER = cub3d.h

OBJECTS = $(SRCS:%.c=%.o)

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

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@printf "\033[K\033[0;35mCompiling the files... : \033[0;33m%s\r" "$<"

clean:
	@$(MAKE_LIBFT) clean
	@${MAKE_MLX} clean > /dev/null 2>&1
	@$(RM) $(OBJECTS)
	@printf "\033[0;31mAll objects files removed.\033[0m\n"

fclean: clean
	@$(MAKE_LIBFT) fclean
	@$(RM) $(NAME)
	@printf "\033[0;31mBinary destroyed.\n\033[0m"

re: fclean all

.PHONY: all clean fclean re
