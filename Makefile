### COLORS ###
GREEN   = \033[1;32m
CYAN    = \033[1;36m
BLUE    = \033[1;34m
RED     = \033[1;31m
YELLOW  = \033[1;33m
WHITE   = \033[1;37m
NOC     = \033[0m

### COMPILATION ###
NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = LIBFT/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = src/

SRC_1 = src/push_swap/push_swap.c \

SRC_2 = src/push_swap/algor.c \
        src/push_swap/ft_add_back.c \
        src/push_swap/ft_stack_new.c \
        src/push_swap/ft_check_utils.c \
        src/push_swap/ft_parse.c \
        src/push_swap/solv_util_ab.c \
        src/push_swap/solv_util_ba.c \
        src/push_swap/ft_rotate_and_push.c \
        src/push_swap/operat.c \
        src/push_swap/operat1.c \
        src/push_swap/operat2.c \
        src/push_swap/ft_check_dup.c \
        src/push_swap/ft_check_sorted.c \
        src/push_swap/ft_error_print.c \
        src/push_swap/ft_free.c \
        src/push_swap/lst_utils.c \
        src/push_swap/lst_utils1.c \
        src/push_swap/ft_parse_args_quoted.c \
        src/push_swap/ft_list_args.c \
        src/push_swap/ft_check_args.c \
        src/push_swap/ft_sort_big.c \
        src/push_swap/ft_sort_three.c \
        src/push_swap/ft_rotate_type.c \
        src/push_swap/handling_process.c \

BONUS_SRC = src/checker/checker.c \
            src/checker/checker_ut.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

INCLUDE = ./LIBFT/libft.a

### RULES ###
.c.o:
	@echo "$(BLUE)Compiling: $(NOC)$< -> $(YELLOW)$@$(NOC)"
	${CC} $(FLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	@echo "$(CYAN)Building Libft...$(NOC)"
	@make -C $(LIBFTDIR)
	@echo "$(CYAN)Creating executable: $(GREEN)${NAME}$(NOC)"
	@${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
	@echo "$(GREEN)Executable $(NAME) created successfully!$(NOC)"

${BONUS}: ${OBJ_2} ${BONUS_OBJ}
	@echo "$(CYAN)Building Libft...$(NOC)"
	@make -C $(LIBFTDIR)
	@echo "$(CYAN)Creating executable: $(GREEN)${BONUS}$(NOC)"
	@${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}
	@echo "$(GREEN)Executable $(BONUS) created successfully!$(NOC)"

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
	@echo "$(RED)Cleaning object files...$(NOC)"
	@${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "$(RED)Object files removed.$(NOC)"

fclean: clean
	@echo "$(RED)Removing executables...$(NOC)"
	@${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "$(RED)Executables removed.$(NOC)"

re: fclean all

.PHONY: all clean fclean re bonus
