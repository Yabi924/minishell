# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 02:58:16 by yyan-bin          #+#    #+#              #
#    Updated: 2025/02/26 22:37:19 by yyan-bin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_striteri.c \
	ft_printf.c printc.c prints.c printd.c printu.c printhex.c printp.c \
	get_next_line.c \

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)

$(NAME): $(OBJ)
	@echo Compling libft...
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)
	@echo clean $(NAME)

re: fclean all
