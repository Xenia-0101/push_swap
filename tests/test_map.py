from cffi import FFI
from utils import header

ffi = FFI()

ffi.cdef(header)

lib = ffi.dlopen("./libpushswap.so")

def test_map_new_creates_map():
    stack = lib.stack_new(5)
    map = lib.map_new(stack)

    assert map.stack_a.value == 5
    assert map.stack_b == ffi.NULL

