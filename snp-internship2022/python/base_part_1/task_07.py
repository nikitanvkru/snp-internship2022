"""
Анаграмма — литературный приём, состоящий в перестановке букв или звуков
определённого слова (или словосочетания), что в результате даёт другое слово
или словосочетание.
Разработайте метод combine_anagrams(words_array), который принимает на вход
массив слов и разбивает их в группы по анаграммам, регистр букв не имеет
значения при определении анаграмм.
"""


def combine_anagrams(words_array):
    anngrams = []
    while len(words_array) > 0:
        to_add = [words_array[0]]
        pattern = ''.join(sorted(words_array[0]))
        for i in words_array[1::]:
            if pattern == ''.join(sorted(i)):
                to_add.append(i)
        for j in to_add:
            words_array.remove(j)
        anngrams.append(to_add)

    return anngrams


if __name__ == '__main__':
    print(combine_anagrams(["cars", "for", "potatoes", "racs", "four", "scar", "creams", "scream"]))
