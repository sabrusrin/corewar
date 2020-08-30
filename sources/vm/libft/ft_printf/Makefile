# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:04:47 by adavis            #+#    #+#              #
#    Updated: 2019/09/22 13:51:03 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I../
SRC 	=	ft_printf.c \
			parse.c \
			set_flags.c \
			handlers.c \
			c_render.c \
			s_render.c \
			d_render.c \
			d_render_zeros.c \
			d_render_short.c \
			o_render.c \
			o_empty.c \
			x_render.c \
			x_empty.c \
			p_render.c \
			u_render.c \
			f_render.c \
			perc_render.c \
			ft_putnbr_base.c
OBJ		=	$(SRC:%.c=%.o)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	cp ../libft.a .
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp libft.a ../

%.o: %.c %.h

DEPS:
	make -C ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
