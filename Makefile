NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	push_swap.c ft_push.c ft_reverse.c ft_rotate.c ft_swap.c lst_utils.c ft_lis.c sortlittle.c utils.c movement.C

SRC_BONUS	=	

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

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re