# **************************************************************************** #
	#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 10:38:54 by steh              #+#    #+#              #
#    Updated: 2021/12/06 10:51:42 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= libftprintf.a
CC			:= gcc
CP			:= cp
AR			:= ar rcs
CFLAGS		:= -Wall -Werror -Wextra
INDIR		= includes/
LIBFT		= libft/libft.a
LIB_FILES	= $(wildcard *.c)
HEADERS		= ft_printf.h

OBJ_FILES	= $(LIB_FILES:%.c = %.o)

all			: $(NAME)

$(NAME)		: $(OBJ_FILES)
				make -C ./libftprintf
				$(CP) $(LIBFT) $(NAME)
				$(CC) -c $(HEADERS) $(LIB_FILES)
				$(AR) $(NAME) $(OBJ_FILES)
clean:
		@echo "Cleaning..."
		rm -rf $(NAME) $(OBJ_FILES)

fclean:
		rm -rf $(NAME)

re		: fclean all

norm	:
		@norminette $(LIB_FILES)

.PHONY	: clean fclean all re norm