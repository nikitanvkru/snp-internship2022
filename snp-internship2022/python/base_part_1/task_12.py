"""
Создайте класс JellyBean, расширяющий класс Dessert (из Упражнения 11) новым
геттером и сеттером для атрибута flavor (все параметры являются не
обязательными). Измените метод is_delicious таким образом, чтобы он возвращал
false только в тех случаях, когда flavor равняется «black licorice».
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

    def is_delicious(self):
        return True


class JellyBean(Dessert):
    def __init__(self, flavor=None):
        super().__init__()
        self.__flavor = flavor

    @property
    def flavor(self):
        return self.__flavor

    @flavor.setter
    def flavor(self, flavor):
        self.__flavor = flavor

    def is_delicious(self):
        if self.__flavor is None:
            return "We don't know ;("
        elif self.__flavor == "black licorice":
            return False
        else:
            return True


jelly_1 = JellyBean()
print("name: ", jelly_1.name, "calories: ", jelly_1.calories, "flavor: ", jelly_1.flavor)
print("is_delicious() method:", jelly_1.is_delicious(), "is_healthy() method:", jelly_1.is_healthy())
print("--------------------")
jelly_2 = JellyBean()
jelly_2.name = "Cake"
jelly_2.calories = 345
jelly_2.flavor = "black licorice"
print("name: ", jelly_2.name, "calories: ", jelly_2.calories, "flavor: ", jelly_2.flavor)
print("is_delicious() method:", jelly_2.is_delicious(), "is_healthy() method:", jelly_2.is_healthy())
print("--------------------")
jelly_3 = JellyBean()
jelly_3.name = "Honey"
jelly_3.calories = 121
jelly_3.flavor = "honey"
print("name: ", jelly_3.name, "calories: ", jelly_3.calories, "flavor: ", jelly_3.flavor)
print("is_delicious() method:", jelly_3.is_delicious(), "is_healthy() method:", jelly_3.is_healthy())
