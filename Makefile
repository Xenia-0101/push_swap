NAME = push_swap
CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf
CC = cc
AR = ar rc

SRCS = src/
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
		${ACTS}ft_pun_rotate.c \
		${SRCS}ft_free.c \
		${SRCS}ft_init.c \
		${SRCS}ft_is_unique.c \
		${SRCS}ft_is_sorted.c \
		${SRCS}ft_parse_args.c \
		${SRCS}ft_sort_reverse.c \
		${SRCS}ft_sort.c \
		${SRCS}ft_sort_big_1.c \
		${SRCS}ft_sort_big_2.c \
		${SRCS}ft_sort_mini.c \
		${SRCS}ft_pun.c \
		${LSTS}ft_dlstadd_back.c \
		${LSTS}ft_dlstadd_front.c \
		${LSTS}ft_dlstclear.c \
		${LSTS}ft_dlstdelone.c \
		${LSTS}ft_dlstiter_1.c \
		${LSTS}ft_dlstiter_2.c \
		${LSTS}ft_dlstlast.c \
		${LSTS}ft_dlstnew.c \
		${LSTS}ft_dlstsize.c \
		${UTLS}ft_atoi_check.c \
		${UTLS}ft_manage_idx.c \
		${UTLS}ft_write.c \
		${UTLS}ft_utils_1.c \
		${UTLS}ft_utils_2.c \

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
