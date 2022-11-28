"""
Разработать методы для программы Камень-Ножницы-Бумага.
Метод rps_game_winner должен принимать на вход массив следующей структуры
[ ["player1", "P"], ["player2", "S"] ], где P - бумага, S - ножницы, R - камень, и
функционировать следующим образом:

• если количество игроков больше 2 необходимо вызывать исключение
WrongNumberOfPlayersError
• если ход игроков отличается от ‘R’, ‘P’ или ‘S’ необходимо вызывать
исключение NoSuchStrategyError
• в иных случаях необходимо вернуть имя и ход победителя, если оба
игрока походили одинаково - выигрывает первый игрок.
"""


class WrongNumberOfPlayersError(Exception):
    def __init__(self, text):
        self.txt = text


class NoSuchStrategyError(Exception):
    def __init__(self, text):
        self.txt = text


def rps_game_winner(array):
    if len(array) != 2:
        raise WrongNumberOfPlayersError("Must be 2 players")

    elif array[0][1] not in ['R', 'P', 'S'] or array[1][1] not in ['R', 'P', 'S']:
        raise NoSuchStrategyError("Strategy must be 'R' or 'P' or 'S'")

    else:
        if array[0][1] == array[1][1]:
            return array[0][0] + " " + array[0][1]
        elif array[0][1] == 'R' and array[1][1] == 'P':
            return array[0][0] + " " + array[0][1]
        elif array[0][1] == 'R' and array[1][1] == 'S':
            return array[1][0] + " " + array[1][1]
        elif array[0][1] == 'P' and array[1][1] == 'S':
            return array[0][0] + " " + array[0][1]
        elif array[0][1] == 'P' and array[1][1] == 'S':
            return array[1][0] + " " + array[1][1]
        elif array[0][1] == 'S' and array[1][1] == 'P':
            return array[0][0] + " " + array[0][1]
        elif array[0][1] == 'S' and array[1][1] == 'R':
            return array[1][0] + " " + array[1][1]


if __name__ == '__main__':
    # print(rps_game_winner([1, 2, 2]))
    # print(rps_game_winner([['player1', 'P'], ['player2', 'A']]))
    print(rps_game_winner([['player1', 'R'], ['player2', 'R']]))
    print(rps_game_winner([['player1', 'P'], ['player2', 'S']]))
    print(rps_game_winner([['player1', 'S'], ['player2', 'R']]))
