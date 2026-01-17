import pytest

# @pytest.mark.parametrize("vals, exp_res", [([], []), ([1, 2, 3], [1, 2, 3])])
# def test_map_new_creates_map(vals, exp_res, lib, stack_factory, assert_stack_values):
#     stack = stack_factory(*vals)
#     map = lib.map_new(stack[0])

#     assert_stack_values(map[0].stack_a, exp_res)



def test_map_new_creates_map_simple(stack_factory, assert_stack_values, ffi, lib):
    stack = stack_factory(1, 2, 3)
    map = lib.map_new(stack[0])

    assert_stack_values(map[0].stack_a, [1, 2, 3])

    assert map.stack_b == ffi.NULL

def test_map_factory_creates_map(map_factory, assert_stack_values, assert_stack_size, ffi):
    map = map_factory(1, 2, 3)

    assert_stack_values(map[0].stack_a, [1, 2, 3])
    assert_stack_size(map[0].stack_a, 3)
    assert map.stack_b == ffi.NULL
