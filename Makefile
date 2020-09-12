# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 13:28:55 by lkarlon-          #+#    #+#              #
#    Updated: 2020/08/31 21:08:25 by lkarlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM					:=	asm
VM					:=	corewar

VPATH				:=	./src/ ./includes/

SRC_NAME_ASM		:=	asm.c								\
						asm_read_and_save.c					\
						asm_define_word.c					\
						asm_definition_1.c					\
						asm_definition_2.c					\
						asm_errors.c						\
						asm_init_1.c						\
						asm_init_2.c						\
						asm_debug.c							\
						asm_new_struct.c					\
						asm_translator.c					\
						asm_write_file.c					\
						asm_put_name_and_comment.c			\
						asm_prepare_operations.c			\
						asm_put_code.c						\
						asm_process_negative_arg_val.c		\
						asm_check_operations_1.c			\
						asm_check_operations_2.c			\
						asm_check_operations_3.c			\
						asm_check_operations_4.c			\
						asm_word_is_what.c					\
						asm_get_f_arr.c						\
						asm_check_arg.c						\
						asm_get_operation_parameters.c		\
						asm_get_label_distance.c			\
						asm_free.c

SRC_NAME_VM			:=	usage.c								\
						corewar.c							\
						parse_argv.c						\
						init_champ.c						\
						operate.c							\
						operate2.c							\
						operate3.c							\
						operate4.c							\
						cycles.c							\
						utilities.c							\
						load_field.c						\
						op.c								\
						process.c							\
						param_setup.c						\
						operations1.c						\
						operations2.c						\
						operations3.c						\
						operations4.c						\
						dump.c								\
						intro.c								\
						argv_utilities.c					\
						parse_utilities.c					\
						exit.c

HEAD_NAME_ASM		:=	asm.h
HEAD_NAME_VM		:=	corewar.h
HEAD_NAME_COMMON	:=	op.h
HEAD_NAME_ASM		+=	$(HEAD_NAME_COMMON)
HEAD_NAME_VM		+=	$(HEAD_NAME_COMMON)

LIB_NAME			:=	libft.a

OBJ_NAME_ASM		:=	$(SRC_NAME_ASM:.c=.o)
OBJ_NAME_VM			:=	$(SRC_NAME_VM:.c=.o)

SRC_PATH			:=	./sources
HEAD_PATH			:=	./includes
LIB_PATH			:=	./libft

SRC_PATH_ASM		:=	$(SRC_PATH)/asmа
SRC_PATH_VM			:=	$(SRC_PATH)/vm/src

CFLAGS				:=	-Wall -Wextra -Werror 

OBJ_PATH			:=	./objects

SRC_ASM				:=	$(addprefix $(SRC_PATH_ASM)/, $(SRC_NAME_ASM))
SRC_VM				:=	$(addprefix $(SRC_PATH_VM)/, $(SRC_NAME_ASM))

OBJ_ASM				:=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME_ASM))
OBJ_VM				:=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME_VM))

HEAD_ASM			:=	$(addprefix $(HEAD_PATH)/, $(HEAD_NAME_ASM))
HEAD_VM				:=	$(addprefix $(HEAD_PATH)/, $(HEAD_NAME_VM))

OBJ					:=	$(OBJ_ASM) $(OBJ_VM)

LIBFT				:=	$(LIB_PATH)/$(LIB_NAME)

CC					:=	gcc
CPPFLAGS			:=	-I $(HEAD_PATH)								\
						-I $(LIB_PATH)/includes						

LIBS_ASM			:=	-L$(LIB_PATH) -lft
LIBS_VM				:=	$(LIBS_ASM)									

all: $(VM)
#all: $(ASM) $(VM)

$(ASM): $(LIBFT) $(OBJ_ASM) $(HEAD_ASM)
	@$(CC) $(CFLAGS) $(LIBS_ASM) $(CPPFLAGS) $(OBJ_ASM) -o $@
	@echo "$(GREEN)[$@ Compiled]$(DEFAULT)"

$(VM): $(LIBFT) $(OBJ_VM)
	@$(CC) $(CFLAGS) $(LIBS_VM) $(CPPFLAGS) $(OBJ_VM) -o $@
	@echo "$(GREEN)[$@ Compiled]$(DEFAULT)"

$(OBJ_PATH)/%.o: $(SRC_PATH_VM)/%.c $(HEAD_VM)
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

	#$(CC) $(CFLAGS) -o $@ -c $< -I$(HEAD_VM)

#$(OBJ_PATH)/%.o : $(SRC_PATH_ASM)/%.c $(HEAD_ASM)
#	@echo [CC] $<
#	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

#$(OBJ_PATH)/%.o : $(SRC_PATH_VM)/%.c $(HEAD_VM)
#	@echo [CC] $<
#	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIB_PATH)

norm:
	@norminette **/*.[ch]

clean:
	@$(MAKE) -C $(LIB_PATH) $@
	@rm -f $(OBJ)
	@echo "$(YELLOW)[Corewar Objects Removed]$(DEFAULT)"

fclean: clean
	@$(MAKE) -C $(LIB_PATH) $@
	@rm -f $(VM)
	@echo "$(RED)[Corewar exe Removed]$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re norm
