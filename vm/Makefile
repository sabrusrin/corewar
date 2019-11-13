NAME		=	corewar
CC			=	gcc
CFLAGS		=	-Ilibft -I. -g
EXTRAS		=	-Wall -Werror -Wextra
LIBFT		=	-Llibft -lft
SRC			=	corewar.c \
				arena.c \
				memcell.c \
				hex.c \
				champs.c \
				heads.c \
				exit.c \
				cycle.c \
				args.c
OBJ			=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): DEPS $(OBJ)
	gcc $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(NAME).h
	$(CC) $(CFLAGS) -o $@ -c $<

DEPS:
	make -C libft/

clean:
	make -C libft $@
	rm -f $(OBJ)

fclean: clean
	make -C libft $@
	rm -f $(NAME)

re: fclean all
