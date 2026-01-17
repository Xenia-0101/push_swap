import pytest 
from cffi import FFI
from utils import header

@pytest.fixture(scope="session")
def ffi():
    ffi_instance = FFI()
    ffi_instance.cdef(header)
    return ffi_instance

@pytest.fixture(scope="session")
def lib(ffi):
    return ffi.dlopen("./libpushswap.so")

@pytest.fixture
def empty_stack(ffi):
    return ffi.new("t_node **")

# ---------------------------------------------------------- #
#                           Factories                        #
# ---------------------------------------------------------- #

@pytest.fixture
def stack_factory(ffi, lib):
    def _create_stack(*values):
        stack = ffi.new("t_node **")
        for value in values:
            lib.stack_add_back(stack, lib.stack_new(value))
        return stack
    return _create_stack

@pytest.fixture
def map_factory(ffi, lib, stack_factory):
    def _create_map(*values):
        if not values:
            return lib.map_new(lib.stack_new(0))
        stack = stack_factory(*values)
        return lib.map_new(stack[0])
    return _create_map

# ---------------------------------------------------------- #
#                           Assertions                       #
# ---------------------------------------------------------- #

@pytest.fixture
def assert_stack_size(ffi):
    def _assert(stack, size):
        current = stack
        len = size
        while current:
            len -= 1
            current = current.next
        assert len == 0, f"Expected size: {size}, got {size - len}"
    return _assert

@pytest.fixture
def assert_stack_empty(ffi):
    def _assert(stack):
        current = stack
        len = 0
        while current != ffi.NULL:
            current = current.next
            len += 1
        assert stack.value == ffi.NULL, f"Stack has {len} elements"
    return _assert

@pytest.fixture
def assert_stack_values(ffi):
    def _assert(stack, expected_values):
        current = stack
        for i, expected in enumerate(expected_values):
            assert current != ffi.NULL, f"Stack ended early at position {i}"
            assert current.value == expected, f"Position {i}: expected {expected}, got {current.value}"
            current = current.next
        assert current == ffi.NULL, "Stack has extra elements"
    return _assert


@pytest.fixture
def assert_map_values(assert_stack_values):
    def _assert(map, expected_a, expected_b):
        assert_stack_values(map.stack_a, expected_a)
        assert_stack_values(map.stack_b, expected_b)
    return _assert