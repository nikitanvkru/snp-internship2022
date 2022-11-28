"""
Дан список целых чисел. Необходимо разработать метод sort_list(list),который
поменяет местами все минимальные и максимальные элементы массива, а также
добавит в конец массива одно минимальное значение из него.
"""


def sort_list(list_task):
    if len(list_task) == 0:
        return []
    else:
        min_max_elements = []
        while len(min_max_elements) < len(list_task):
            current_max = max(list(set(list_task) - set(min_max_elements)))
            current_min = min(list(set(list_task) - set(min_max_elements)))
            list_task = [current_min if x == current_max else current_max if x == current_min else x for x in list_task]
            min_max_elements.extend(([x for x in list_task if x == current_max or x == current_min]))

        list_task.append(min(list_task))
        return list_task


if __name__ == '__main__':
    print(sort_list([]))
    print(sort_list([2, 4, 6, 8]))
    print(sort_list([1]))
    print(sort_list([1, 2, 1, 3]))
    print(sort_list([1, 1, 1, 1, 1, 1, 2]))
    print(sort_list([1, 1, 1, 1, 4, 2, 3, 3, 3, 3, 3, 3, 3]))
