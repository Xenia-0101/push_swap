import subprocess

def run_push_swap(args):
    result = subprocess.run(
        ["./push_swap", *map(str, args)],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        check=True,
    )
    return result.stdout.strip().splitlines()


def apply_operations(stack, ops):
    a = stack[:]
    b = []

    for op in ops:
        if op == "sa" and len(a) >= 2:
            a[0], a[1] = a[1], a[0]

        elif op == "pb" and a:
            b.insert(0, a.pop(0))

        elif op == "pa" and b:
            a.insert(0, b.pop(0))

        elif op == "ra" and len(a) >= 1:
            a.append(a.pop(0))

        elif op == "rra" and len(a) >= 1:
            a.insert(0, a.pop())

        else:
            raise AssertionError(f"Unknown operation: {op}")

    return a, b


# def test_push_swap_sorts_three():
#     initial = [3, 1, 2]
#     ops = run_push_swap(initial)

#     a, b = apply_operations(initial, ops)

#     assert a == sorted(initial)
#     assert b == []


# *************************************************** #
#                SOME BASIC CASES                     #
# *************************************************** #

# def test_push_swap_no_input():
#     res = run_push_swap()
#     assert res == 1