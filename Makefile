NAME		:= libftprintf.a
CC			:= gcc
AR			:= ar rcs
CFLAGS		:= -Wall -Werror -Wextra -c -g
SRCS		= ./libft/ft*.c ./srcs/ft*.c
OBJS		= ft*.o
LIBFT		= ./libft
INC			= ./includes

# Colors
GREEN		= \033[1;32m
RED			= \033[1;31m


all			: $(NAME)


$(NAME)		: $(OBJS) 
				@make re -C $(LIBFT)
				@$(AR) $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "$(GREEN)ft_printf compiled!"

$(OBJS)		:
				@$(CC) $(CFLAGS) $(SRCS) -I $(INC)

bonus		: all


test			: 
				gcc main.c -g libft/ft*.c srcs/ft*.c -I ./includes -o printf

clean			:
				@echo "$(RED)Cleaning..."
				@rm -rf $(OBJS)
				@make clean -C $(LIBFT)
				@echo "ft_printf object files cleaned"

fclean			: clean
				@rm -rf $(NAME)
				@rm -f $(LIBFT)/libft.a
				@echo "ft_printf executable files cleaned"
				@echo "libft executable files cleaned"

re		: fclean all
		@echo "Cleaned and rebuilt everything for ft_printf"

norm	:
		@norminette $(SRC) $(INC) $(LIBFT) | grep -v Norme -B1 || true

 test.PHONY	: clean fclean all re norm
