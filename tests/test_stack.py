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
#                              &                       #
#                     ** stack_factory **              #
# **************************************************** #

def test_stack_add_back_simple(assert_stack_values, assert_stack_size, stack_factory, ffi):
    stack = stack_factory(5, 10, 15, 20)
    assert stack[0] != ffi.NULL
    assert stack[0].value == 5
    assert stack[0].next.value == 10
    assert stack[0].next.next.value == 15
    assert stack[0].next.next.next.value == 20
    assert stack[0].next.next.next.next == ffi.NULL
    assert_stack_values(stack[0], [5, 10, 15, 20])
    assert_stack_size(stack[0], len([5, 10, 15, 20]))

@pytest.mark.parametrize("vals", [
    [],
    [10],
    [10, 20, 30]
])
def test_stack_add_back(assert_stack_values, assert_stack_size, stack_factory, vals):
    stack = stack_factory(*vals)
    assert_stack_values(stack[0], vals)
    assert_stack_size(stack[0], len(vals))

@pytest.mark.parametrize("vals", [[10, 20], [10, 20, 30]])
def test_stack_add_back_extra_elements_detection(assert_stack_values, stack_factory, vals):
    stack = stack_factory(*vals)
    with pytest.raises(AssertionError, match="Stack has extra elements"):
        assert_stack_values(stack[0], [10]) 

def test_stack_add_back_early_termination_detection(assert_stack_values, stack_factory):
    stack = stack_factory(10)
    with pytest.raises(AssertionError, match="Stack ended early at position 1"):
        assert_stack_values(stack[0], [10, 20])

def test_stack_add_back_null_ptr(stack_factory, ffi):
    stack = stack_factory()
    assert stack[0] == ffi.NULL

def test_stack_add_back_different_elements(assert_stack_values, stack_factory):
    stack = stack_factory(10, 20)
    with pytest.raises(AssertionError):
        assert_stack_values(stack[0], [5, 10])

# **************************************************** #
#               Test     ** stack_size **              #
# **************************************************** #

@pytest.mark.parametrize(
        "vals, exp_size", [
        ([], 0),
        ([10, 20, 30], 3)
        ]
)
def test_stack_size_simple(stack_factory, vals, exp_size, lib):
    stack = stack_factory(*vals)
    assert lib.stack_size(stack[0]) == exp_size



