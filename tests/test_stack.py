from cffi import FFI
from utils import header

ffi = FFI()

ffi.cdef(header)

lib = ffi.dlopen("./libpushswap.so")

def test_stack_new_creates_node():
    stack = lib.stack_new(5)

    assert stack.value == 5
    assert stack.next == ffi.NULL


def test_stack_add_back_single():
    stack = ffi.new("t_node **")

    lib.stack_add_back(stack, lib.stack_new(10))

    assert lib.stack_size(stack[0]) == 1
    assert stack[0].value == 10

def test_stack_add_back_three():
    stack = ffi.new("t_node **")

    lib.stack_add_back(stack, lib.stack_new(10))
    lib.stack_add_back(stack, lib.stack_new(20))
    lib.stack_add_back(stack, lib.stack_new(30))

    assert lib.stack_size(stack[0]) == 3
    assert stack[0].value == 10
    assert stack[0].next.value == 20
    assert stack[0].next.next.value == 30

def test_stack_size_empty():
    stack = ffi.new("t_node **")

    assert lib.stack_size(stack[0]) == 0

def test_stack_size_not_empty():
    stack = ffi.new("t_node **")

    lib.stack_add_back(stack, lib.stack_new(10))
    lib.stack_add_back(stack, lib.stack_new(20))
    lib.stack_add_back(stack, lib.stack_new(30))

    assert lib.stack_size(stack[0]) == 3


