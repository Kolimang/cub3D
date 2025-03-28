# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 11:55:49 by jrichir           #+#    #+#              #
#    Updated: 2025/03/28 14:53:46 by ngharian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =  ./srcs/main.c \
		./srcs/utils.c \
		./srcs/parsing.c \
		./srcs/checking.c \
		./srcs/check_map.c \
		./srcs/render.c \
		./srcs/raycast.c \
		./srcs/raycast_utils.c \
		./srcs/draw.c \
		./srcs/render_utils.c \
		./srcs/key_press_release.c \
		./srcs/move.c \
		./srcs/rotate.c

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
