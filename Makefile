# **************************************************************************** #
	#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 10:38:54 by steh              #+#    #+#              #
#    Updated: 2021/12/07 14:27:48 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC			:= gcc
AR			:= ar rcs
CFLAGS		:= -Wall -Werror -Wextra -c
SRCS		= srcs/ft*.c libft/ft*.c
INCLUDES	= includes/
OBJ_FILES	= $(SRCS:%.c = %.o)

all			: $(NAME)

$(NAME)		: $(OBJ_FILES)
				make -C ./libft
				$(CC) $(CFLAGS) $(SRCS) -I $(INCLUDES)
				$(AR) $(NAME) $(OBJ_FILES)
clean:
		@echo "Cleaning..."
		rm -rf $(NAME) ft*.o

fclean:
		rm -rf $(NAME)

re		: fclean all

norm	:
		@norminette $(LIB_FILES)

.PHONY	: clean fclean all re norm
