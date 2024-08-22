NAME = push_swap
CFLAGS =  -g
# CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf
CC = cc
AR = ar rc

# *** libft library *** #
LIBFT_DIR = libft
LIBFT_NAME = libft.a

# *** source code files *** #
SRC := \
		main.c \

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

# ls *.c | sed 's/$/\\/'
