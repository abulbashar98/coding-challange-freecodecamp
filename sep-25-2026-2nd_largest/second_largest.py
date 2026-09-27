
arr = [1, 0, -1, 0, 1, 0, -1, 1, 0]

def second_largest_element(arr):

    sorted_arr = sorted(set(arr))
    print(sorted_arr)
    return sorted_arr[-2]


print(second_largest_element(arr))

