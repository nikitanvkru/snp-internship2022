"""
Написать метод multiply_numbers(inputs), который вернет произведение цифр,
входящих в inputs.
"""
import re
import math


def multiply_numbers(inputs=None):
    string = str(inputs)
    clear_string = re.findall(r'\d+', string)
    if len(clear_string) == 0:
        return None
    lst = list(map(int, clear_string))
    sum_ans = 1
    for i in lst:
        my_list = [int(x) for x in str(i)]
        sum_ans *= math.prod(my_list)

    return sum_ans


if __name__ == '__main__':
    print(multiply_numbers())
    print(multiply_numbers('ss'))
    print(multiply_numbers('1234'))
    print(multiply_numbers('sssdd34'))
    print(multiply_numbers('1 2 3 4 5'))
    print(multiply_numbers(2.3))
    print(multiply_numbers([5, 6, 4]))
