"""
Необходимо разработать метод connect_dicts(dict1, dict2), который соединит два
переданных словаря, значениями ключей в которых являются числа, и вернет
новый словарь, полученный по следующим правилам:

• приоритетными являются ключи того словаря, сумма значений ключей
которого больше (если суммы значений ключей будут равны, то второй
словарь считается более приоритетным)
• ключи со значениями меньше 10 не должны попасть в финальный
словарь
• получившийся словарь должен вернуться упорядоченным по значениям
ключей в порядке возрастания.
"""


def connect_dicts(dict1, dict2):
    clear_dict1 = {key: val for key, val in dict1.items() if val >= 10}
    clear_dict2 = {key: val for key, val in dict2.items() if val >= 10}

    if sum(dict1.values()) > sum(dict2.values()):
        connected_dict = {**clear_dict2, **clear_dict1}
        return dict(sorted(connected_dict.items(), key=lambda x: x[1]))
    elif sum(dict2.values()) >= sum(dict1.values()):
        connected_dict = {**clear_dict1, **clear_dict2}
        return dict(sorted(connected_dict.items(), key=lambda x: x[1]))


if __name__ == '__main__':
    print(connect_dicts({"a": 10, "b": 12}, {"a": 11, "b": 1}))
    print(connect_dicts({"a": 13, "b": 9, "d": 11}, {"c": 12, "a": 15}))
    print(connect_dicts({"a": 2, "b": 12}, {"c": 11, "e": 5}))
    print(connect_dicts({"a": 14, "b": 12}, {"c": 11, "a": 15}))
