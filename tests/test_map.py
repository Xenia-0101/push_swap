import pytest


def test_map_new_creates_map_simple(stack_factory, assert_map_values, lib):
    stack = stack_factory(1, 2, 3)
    map = lib.map_new(stack[0])
    assert_map_values(map, [1, 2, 3], [])

def test_map_factory_creates_map(map_factory, assert_map_values):
    map = map_factory(1, 2, 3)
    assert_map_values(map, [1, 2, 3], [])

def test_map_factory_early_terminantion_detection(map_factory, assert_map_values):
    map = map_factory(1, 2, 3)
    with pytest.raises(AssertionError):
        assert_map_values(map, [1, 2], [])

@pytest.mark.xfail(reason="Should take care of null pointer passing to map")
def test_map_factory_pass_empty_stack(map_factory, assert_stack_values, assert_stack_size, ffi):
    map = map_factory()
    assert_stack_values(map[0].stack_a, [])
    assert_stack_size(map[0].stack_a, 0)
    assert map.stack_b == ffi.NULL


