from cffi import FFI

ffi = FFI()

ffi.cdef("""
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

t_node *stack_new(int value);
void stack_add_back(t_node **stack, t_node *new);
int stack_size(t_node *stack);
""")

lib = ffi.dlopen("./libpushswap.so")

# def test_stack_size():
#     stack = ffi.new("t_node **")

#     lib.stack_add_back(stack, lib.stack_new(10))
#     lib.stack_add_back(stack, lib.stack_new(20))
#     lib.stack_add_back(stack, lib.stack_new(30))

#     assert lib.stack_size(stack[0]) == 3


def test_stack_new_creates_node():
    stack = lib.stack_new(5)

    assert stack.value == 5
    assert stack.next == ffi.NULL


def test_stack_add_back_single():
    stack = lib.stack_new(3)

    stack = lib.stack_add_back(stack, lib.stack_new(10))

