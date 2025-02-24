# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngharian <ngharian.student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:57:28 by ngharian          #+#    #+#              #
#    Updated: 2023/11/06 14:05:38 by ngharian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./src/libft/ft_isalnum.c ./src/libft/ft_isprint.c ./src/libft/ft_memcmp.c \
    ./src/libft/ft_putchar_fd.c ./src/libft/ft_split.c ./src/libft/ft_strlcat.c \
    ./src/libft/ft_strncmp.c ./src/libft/ft_substr.c ./src/libft/ft_atoi.c \
    ./src/libft/ft_isalpha.c ./src/libft/ft_itoa.c ./src/libft/ft_memcpy.c \
    ./src/libft/ft_putendl_fd.c ./src/libft/ft_strchr.c ./src/libft/ft_strlcpy.c \
    ./src/libft/ft_strnstr.c ./src/libft/ft_tolower.c ./src/libft/ft_bzero.c \
    ./src/libft/ft_isascii.c ./src/libft/ft_memmove.c ./src/libft/ft_putnbr_fd.c \
    ./src/libft/ft_strdup.c ./src/libft/ft_strlen.c ./src/libft/ft_strrchr.c \
    ./src/libft/ft_toupper.c ./src/libft/ft_calloc.c ./src/libft/ft_isdigit.c \
    ./src/libft/ft_memchr.c ./src/libft/ft_memset.c ./src/libft/ft_putstr_fd.c \
    ./src/libft/ft_strjoin.c ./src/libft/ft_strmapi.c ./src/libft/ft_strtrim.c \
    ./src/libft/ft_striteri.c ./src/libft/ft_lstnew.c ./src/libft/ft_lstadd_front.c \
    ./src/libft/ft_lstsize.c ./src/libft/ft_lstlast.c ./src/libft/ft_lstadd_back.c \
    ./src/libft/ft_lstdelone.c ./src/libft/ft_lstclear.c ./src/libft/ft_lstiter.c \
    ./src/libft/ft_lstmap.c ./src/libft/ft_isspace.c \
    ./src/ft_printf/ft_printf.c ./src/ft_printf/ft_putchar.c ./src/ft_printf/ft_putnbr.c \
    ./src/ft_printf/ft_putstr.c ./src/ft_printf/ft_puthexa.c ./src/ft_printf/ft_put_unsigned.c \
    ./src/ft_printf/ft_put_ptr.c\
    ./src/get_next_line/get_next_line.c ./src/get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

INCL = /libft.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ${INCL}

BNS = ./src/libft/ft_lstnew.c ./src/libft/ft_lstadd_front.c \
      ./src/libft/ft_lstsize.c ./src/libft/ft_lstlast.c \
      ./src/libft/ft_lstadd_back.c ./src/libft/ft_lstdelone.c \
      ./src/libft/ft_lstclear.c ./src/libft/ft_lstiter.c \
      ./src/libft/ft_lstmap.c
	
OBJ_BNS = ${BNS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean : 
	rm -f ${OBJS} ${OBJ_BNS}

fclean : clean 
	rm -f ${NAME}

re : fclean all

bonus : ${OBJS} ${OBJ_BNS}
	ar -rcs ${NAME} ${OBJS} ${OBJ_BNS}

.PHONY : all clean fclean re
