"""
Разработайте метод is_palindrome(string), который будет определять, является ли
параметр string палиндромом (строкой, которая читается одинаково как сначала
так и с конца), при условии игнорирования пробелов, знаков препинания и
регистра.
"""
import re


def is_palindrome(string):
    clear_string = re.findall(r'[a-zA-Z]+', str(string))
    return True if ("".join(clear_string).lower() == "".join(clear_string).lower()[::-1]) else False


if __name__ == '__main__':
    print(is_palindrome("A man, a plan, a canal -- Panama"))
    print(is_palindrome("Madam, I'm Adam!"))
    print(is_palindrome(333))
    print(is_palindrome(None))
    print(is_palindrome("Abracadabra"))
    print(is_palindrome(" __"))
    print(is_palindrome("  "))
