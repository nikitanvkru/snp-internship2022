"""
Реализуйте класс Dessert c геттерами и сеттерами name и calories, конструктором,
принимающим на вход name и calories (не обязательные параметры), а также двумя
методами is_healthy (возвращает true при условии калорийности десерта менее
200) и is_delicious (возвращает true для всех десертов).
P.S.: Рекомендуем использовать декоратор @property для реализации данного и
следующего упражнения
"""


class Dessert:

    def __init__(self, name=None, calories=None):
        self.__name = name
        self.__calories = calories

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, name):
        self.__name = name

    @property
    def calories(self):
        return self.__calories

    @calories.setter
    def calories(self, calories):
        self.__calories = calories

    def is_healthy(self):
        if self.__calories is None:
            return "We don't know ;("
        elif self.__calories < 200:
            return True
        else:
            return False

    @staticmethod
    def is_delicious():
        return True


desert = Dessert()
print("name: ", desert.name, "calories: ", desert.calories)
print("is_delicious() method:", desert.is_delicious(), "is_healthy() method:", desert.is_healthy())
print("--------------------")
desert_1 = Dessert()
desert_1.name = "Cake"
desert_1.calories = 345
print("name: ", desert_1.name, "calories: ", desert_1.calories)
print("is_delicious() method:", desert_1.is_delicious(), "is_healthy() method:", desert_1.is_healthy())
print("--------------------")
desert_2 = Dessert()
desert_2.name = "Banana"
desert_2.calories = 25
print("name: ", desert_2.name, "calories: ", desert_2.calories)
print("is_delicious() method:", desert_2.is_delicious(), "is_healthy() method:", desert_2.is_healthy())
