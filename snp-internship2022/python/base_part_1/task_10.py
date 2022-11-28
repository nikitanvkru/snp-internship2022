"""
Разработайте функцию count_words(string), которая будет возвращать словарь со
статистикой частоты употребления входящих в неё слов.
"""
import re


def count_words(string):
    clear_string = re.sub(r'[^a-zA-Z]+', ' ', str(string))
    words_list = clear_string.lower().split()
    ans_dict = {}
    for word in words_list:
        if word in ans_dict:
            ans_dict[word] += 1
        else:
            ans_dict[word] = 1
    return ans_dict


if __name__ == '__main__':
    print(count_words("A man, a plan, a canal -- Panama"))
    print(count_words("Doo bee doo bee doo"))
    print(count_words("!@as#$plan^&,    nik ()*&^^ kik kik"))
