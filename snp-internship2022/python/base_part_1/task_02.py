"""
Дан список list и числовой диапазон range. Разработайте метод coincidence(list,
range) для определения элементов из массива list, значения которого входят в
указанный диапазон range. Если не передан хотя бы один из параметров, то
должен вернуться пустой массив.
"""
import numbers


def coincidence(list=None, range=None):
    answer_list = []
    if list is None or range is None:
        return []

    for i in list:
        if isinstance(i, numbers.Number):
            if range[-1] >= i >= range[0]:
                answer_list.append(i)

    answer_list.sort()
    return answer_list


if __name__ == '__main__':
    print(coincidence())
    print(coincidence([1, 2, 3, 4, 5], range(3, 6)))
    print(coincidence([None, 1, 'foo', 4, 2, 2.5], range(1, 4)))
