import functools


def cmp(a, b):
    if a[0] < b[0]:
        return -1
    elif a[0] > b[0]:
        return 1
    else:
        if a[1] < b[1]:
            return -1
        else:
            return 1


if __name__ == "__main__":
    array = [[4, 4], [2, 2], [1, 2], [5, 5]]
    new_array = sorted(array, key=functools.cmp_to_key(cmp))
    print(new_array)
