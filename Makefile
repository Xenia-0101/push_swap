NAME = push_swap
# CFLAGS =  -g
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf
CC = cc
AR = ar rc

LSTS = src/lists/
UTLS = src/utils/
ACTS = src/actions/

# *** libft library *** #
LIBFT_DIR = libft
LIBFT_NAME = libft.a

# *** source code files *** #
SRC := \
		main.c \
		${ACTS}ft_push.c \
		${ACTS}ft_swap.c \
		${ACTS}ft_rotate.c \
		${ACTS}ft_rrotate.c \
		src/utils.c \
		src/ft_free.c \
		src/ft_init.c \
		src/ft_is_unique.c \
		src/ft_is_sorted.c \
		src/ft_parse_args.c \
		src/ft_sort_reverse.c \
		src/ft_sort.c \
		src/ft_sort_mini.c \
		src/ft_pun.c \
		${LSTS}ft_dlstadd_back.c \
		${LSTS}ft_dlstadd_front.c \
		${LSTS}ft_dlstclear.c \
		${LSTS}ft_dlstdelone.c \
		${LSTS}ft_dlstiter.c \
		${LSTS}ft_dlstlast.c \
		${LSTS}ft_dlstnew.c \
		${LSTS}ft_dlstsize.c \
		${UTLS}ft_atoi_check.c \
		${UTLS}ft_manage_idx.c \
		# ${LSTS}ft_actadd_back.c \
		# ${LSTS}ft_actadd_front.c \
		# ${LSTS}ft_actclear.c \
		# ${LSTS}ft_actdelone.c \
		# ${LSTS}ft_actiter.c \
		# ${LSTS}ft_actlast.c \
		# ${LSTS}ft_actnew.c \
		# ${LSTS}ft_actsize.c \
		# ${LSTS}ft_test_act.c \



OBJ = $(SRC:.c=.o)
HEADER = -I ./include/

all: libft ${NAME}
	@echo "push_swap executable is ready"

%.o: %.c
	@${CC} ${CFLAGS} -c $< $(HEADER) -o $@

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ} libft.a ${MLX_LIB}

# *** compile libft *** #
libft:
	@make -C libft
	@mv libft/libft.a ./
	@echo "libft library is ready"

# *** general rules *** #
clean:
	${RM} ${OBJ}
	make clean -C ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME} ${LIBFT_NAME}

re: fclean all

.PHONY: all clean fclean re libft

# ls *.c | sed 's/$/ \\/'
