.PHONY: all clean fclean re norm libs clean_name

NAME = asm

CC = gcc

#BIN_DIR = ../resources
BIN_DIR ?= .

CDIR = srcs
HDIR = includes
ODIR = objects

LBDIRS = libft
LBNAMES = libft.a

LDFLAGS += $(addprefix -L , $(LBDIRS))
LDLIBS += $(addprefix -l , $(LBNAMES:lib%.a=%))

INCDIRS = $(HDIR) $(LBDIRS) $(addsuffix /includes, $(LBDIRS))

# DBCFLAGS = -Wno-error -g
OPTFLAGS = -O3
CFLAGS = -g -Wall -Wextra -Werror -MD $(addprefix -I , $(INCDIRS)) $(DBCFLAGS) $(OPTFLAGS)

SOURCES = main.c \
		asm.c \
		init.c \
		tokenize.c \
		token_create.c \
		label_instr_reg_token_create.c \
		filename_check.c \
		error.c \
		helper.c \
		parse_tokens.c \
		parse_instruction.c \
		calc_size.c \
		translate.c \
		parse_args.c

OBJECTS = $(addprefix $(ODIR)/, $(SOURCES:.c=.o))
DEPS = $(OBJECTS:.o=.d)

all: libs $(ODIR) $(BIN_DIR) $(BIN_DIR)/$(NAME)

$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/$(NAME): $(OBJECTS)
	$(LINK.o) $^ $(LDLIBS) -o $@

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(CDIR)/%.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

clean:
	rm -rf $(ODIR)
	@for i in $(LBDIRS); do \
		if ! $(MAKE) -C $$i fclean 2> /dev/null; then \
			$(MAKE) -C $$i clean; \
		fi; \
	done

clean_name:
	rm -f $(BIN_DIR)/$(NAME)

fclean: clean clean_name

re: fclean all

norm:
	norminette $(CDIR)/* $(HDIR)/*

MAKEOVERRIDES =
libs:
	@for i in $(LBDIRS); do \
		make -C $$i 2> /dev/null ; \
	done

-include $(wildcard $(DEPS))