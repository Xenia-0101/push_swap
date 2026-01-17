import pytest


# -----------------------------------------------------------------------------#
# test sa function
# -----------------------------------------------------------------------------#

'''
void sa(t_map *map){
    int c;

    if (!map || !map->stack_a)
        return;
    if (stack_size(map->stack_a) < 2)
        return;
    
    c = map->stack_a->value;
    map->stack_a->value = map->stack_a->next->value;
    map->stack_a->next->value = c;
}
'''
@pytest.mark.parametrize("vals, exp_vals", 
                         [([], []), 
                          ([10], [10]), 
                          ([10, 20], [20, 10]), 
                          ([10, 20, 30], [20, 10, 30]),
                          ([10, 20, 30], [10, 20, 30])])
def test_sa_new_map_with_one_node(map_factory, assert_map_values, lib, vals, exp_vals):
    map = map_factory(*vals)
    lib.sa(map)
    assert_map_values(map, exp_vals, [])

def test_sa_new_map_with_one_node(map_factory, assert_map_values, lib):
    map = map_factory(10, 20, 30)
    lib.sa(map)
    assert_map_values(map, [20, 10, 30], [])



# def test_sa_new_map_with_one_node():
#     stack = lib.stack_new(5)
#     map = lib.map_new(stack)
#     lib.sa(map)
#     assert map.stack_a.value == 5

# def test_sa_map_with_two_nodes():
#     stack = ffi.new("t_node **")
#     lib.stack_add_back(stack, lib.stack_new(10))
#     lib.stack_add_back(stack, lib.stack_new(5))
    

#     map = lib.map_new(stack[0])
#     assert map.stack_a.value == 10
#     lib.sa(map)
#     assert map.stack_a.value == 5

# def test_sa_map_with_multiple_nodes():
#     stack = ffi.new("t_node **")
#     lib.stack_add_back(stack, lib.stack_new(5))
#     lib.stack_add_back(stack, lib.stack_new(10))
#     lib.stack_add_back(stack, lib.stack_new(15))
#     lib.stack_add_back(stack, lib.stack_new(50))
#     lib.stack_add_back(stack, lib.stack_new(100))
    
#     map = lib.map_new(stack[0])
#     lib.sa(map)

#     assert map.stack_a.value == 10
#     assert map.stack_a.next.value == 5
#     assert map.stack_a.next.next.value == 15
#     assert map.stack_a.next.next.next.value == 50
#     assert map.stack_a.next.next.next.next.value == 100

# def test_sa_twice_map_with_multiple_nodes():
#     stack = ffi.new("t_node **")
#     lib.stack_add_back(stack, lib.stack_new(5))
#     lib.stack_add_back(stack, lib.stack_new(10))
#     lib.stack_add_back(stack, lib.stack_new(15))
#     lib.stack_add_back(stack, lib.stack_new(50))
#     lib.stack_add_back(stack, lib.stack_new(100))
    
#     map = lib.map_new(stack[0])
#     lib.sa(map)
#     lib.sa(map)

#     assert map.stack_a.value == 5
#     assert map.stack_a.next.value == 10
#     assert map.stack_a.next.next.value == 15
#     assert map.stack_a.next.next.next.value == 50
#     assert map.stack_a.next.next.next.next.value == 100


# -----------------------------------------------------------------------------#
# test sb function
# -----------------------------------------------------------------------------#
