import pytest 

# **************************************************** #
#                 Test  ** stack_new **                #
# **************************************************** #


def test_stack_new_creates_node(lib, ffi):
    stack = lib.stack_new(42)
    assert stack.value == 42
    assert stack.next == ffi.NULL


def test_stack_new_creates_node_no_arg(lib, ffi):
    with pytest.raises(TypeError, match="expects 1 arguments, got 0"):
        lib.stack_new()


def test_stack_new_creates_node_decimal(lib, ffi):
    with pytest.raises(TypeError, match="an integer is required"):
        lib.stack_new(3.6)


# **************************************************** #
#               Test  ** stack_add_back **             #
# **************************************************** #

def test_stack_add_back(lib):
    stack = lib.stack_new(42)

@pytest.mark.parametrize("vals", [
    [10],
    [10, 20, 30]
])
def test_stack_add_back(assert_stack_values, assert_stack_size, stack_factory, vals):
    stack = stack_factory(*vals)
    assert_stack_values(stack[0], vals)
    assert_stack_size(stack[0], len(vals))

@pytest.mark.parametrize(
        "vals, exp_size", [
        ([], 0),
        ([10, 20, 30], 3)
        ]
)
def test_stack_size(stack_factory, vals, exp_size, lib, ffi):
    stack = stack_factory(*vals)
    assert lib.stack_size(stack[0]) == exp_size


# **************************************************** #
#           Test  ** assert_stack_size **              #
# **************************************************** #




