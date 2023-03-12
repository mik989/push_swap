NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	src/push_swap.c \
				src/check_error.c \
				src/ft_push.c \
				src/ft_reverse.c \
				src/ft_rotate.c \
				src/ft_swap.c \
				src/lst_utils.c \
				src/ft_lis.c \
				src/sortlittle.c \
				src/utils.c \
				src/movement.c \
				src/utils_2.c \
				src/ft_ultimate_movement.c \
				src/array_lis.c \
				src/movement_utils.c \
				src/movement_utils_2.c \
				src/ft_pos.c \
				src/ft_long_atoi.c \
				src_bonus/utils_bonus.c

SRC_BONUS	=	src_bonus/checker.c \
				src_bonus/check_error_bonus.c \
				src_bonus/ft_long_atoi_bonus.c \
				src_bonus/ft_push_bonus.c \
				src_bonus/ft_reverse_bonus.c \
				src_bonus/ft_rotate_bonus.c \
				src_bonus/ft_swap_bonus.c \
				src_bonus/lst_utils_bonus.c \
				src_bonus/get_next_line_bonus.c \
				src_bonus/utils_bonus.c

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	gcc -g

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			@echo Libreria compilata!
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)
			@echo File .o e libreria rimossi!

re:			fclean all

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re