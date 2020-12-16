NAME = disasm

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = op.c fun_print.c fun_read1.c fun_read2.c fun_read3.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER_DIR = ../inc/
HEADER_LIST= disasm.h op.h asm.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT_H = ../../libft/includes/
LIBFT_SRC = ../../libft
LIBFT = ../../libft/libft.a

RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT_H) disassembly.c
		@gcc -o $(NAME) disassembly.c $(OBJECTS) -I$(HEADER_DIR) -I$(LIBFT_H) $(LIBFT)
		@echo $(GREEN) disassembly created! $(WHITE)

$(OBJECTS): %.o: %.c $(HEADER) $(LIBFT_H)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER_DIR) -I$(LIBFT_H)
		@echo disassembly file: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_SRC)

clean:
		@/bin/rm -f *.o
		@echo $(WHITE_B) *.o files deleted!$(WHITE)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
