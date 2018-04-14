#!/usr/bin/env python3


def merge_sort(full_list):
    print ("Split", full_list)
    if len(full_list) > 1:
        mid = len(full_list) // 2
        merge_back(full_list, merge_sort(full_list[:mid]), merge_sort(full_list[mid:]))

    return full_list


def merge_back(full_list, left, right):
    left_index = right_index = list_index = 0
    print("Before merge back:", full_list)
    print("Left", left)
    print("Right", right)
    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            full_list[list_index] = left[left_index]
            left_index += 1
        else:
            full_list[list_index] = right[right_index]
            right_index += 1

        list_index += 1

    # either left or right must be empty at this point
    while left_index < len(left):
        full_list[list_index] = left[left_index]
        left_index += 1
        list_index += 1

    while right_index < len(right):
        full_list[list_index] = right[right_index]
        right_index += 1
        list_index += 1

    print("After merge back:", full_list)


data = [4, 7, 8, 1, 6, 9, 3, 2, 5]
merge_sort(data)
print(data)
