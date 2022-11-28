"""
Дан список элементов произвольной природы. Необходимо разработать метод
max_odd(array), который определит максимальный нечетный элемент (21.000 = 21 и
тоже считается нечетным элементом). Вернуть None, если таких элементов нет в
переданном массиве.
"""


def max_odd(array):
    array = [array.extend(x) if isinstance(x, list) else x for x in array]
    new_array = [i for i in array if type(i) == int or type(i) == float]
    odd = filter(lambda n: n % 2 == 1, new_array)
    lst = list(odd)
    return None if len(lst) == 0 else max(lst)


if __name__ == '__main__':
    print(max_odd(['ololo', 2, 3, 4, [1, 2], [12, 13, 123, 1234, 1423, 1231243], None]))
    print(max_odd(['ololo', 2, 3, 4, [1, 2], None]))
    print(max_odd([1, 2, 3, 4, 4]))
    print(max_odd([21.0, 2, 3, 4, 4]))
    print(max_odd(['ololo', 'fufufu']))
    print(max_odd([2, 2, 4]))
    print(max_odd([]))
