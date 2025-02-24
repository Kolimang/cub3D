# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdero <gdero@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 15:12:03 by gdero             #+#    #+#              #
#    Updated: 2024/12/17 17:41:58 by gdero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =  ./srcs/main.c \
		./srcs/errors.c \
		./srcs/parsing.c \
		./srcs/checking.c \
		./srcs/check_map.c

HEADER = cub3d.h

OBJECTS = $(SRCS:%.c=%.o)

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

CC = cc

RM = rm -f

MAKE_LIBFT = make -s -C ./libft

MAKE_MLX = make -s -C ./minilibx-linux

LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx.a

$(NAME): $(OBJECTS)
	@$(MAKE_LIBFT)
	@${MAKE_MLX}
	@$(CC) $(CFLAGS) ${OBJECTS} ${LIBFT} ${MLX} -Lminilibx-linux -lmlx_Linux -o process -lX11 -lXext -I ${HEADER} -o ${NAME}
	@printf "\033[K\033[0;31mThe Binary is ready.\033[0m\n"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@printf "\033[K\033[0;32mCompiling the files... : \033[0;33m%s\r" "$<"
	
all: $(NAME)

clean:
	@$(MAKE_LIBFT) clean
	@${MAKE_MLX} clean
	@$(RM) $(OBJECTS)
	@printf "\033[0;32m All objects files removed.\033[0m\n"

fclean: clean
	@$(MAKE_LIBFT) fclean
	@$(RM) $(NAME)
	@printf "\033[0;31mBinary destroyed.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re