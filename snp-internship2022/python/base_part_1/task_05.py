"""
Разработать метод date_in_future(integer), который вернет дату через integer дней.
Если integer не является целым числом, то метод должен вывести текущую дату.
Формат возвращаемой методом даты должен иметь следующий вид '01-01-2001
22:33:44’.
"""
from datetime import datetime, timedelta


def date_in_future(integer):
    if type(integer) != int:
        return datetime.today().strftime('%d-%m-%Y %H:%M:%S')
    else:
        current_date = datetime.now()
        future_date = current_date + timedelta(days=integer)
        return future_date.strftime('%d-%m-%Y %H:%M:%S')


if __name__ == '__main__':
    print(date_in_future("Vasyan"))
    print(date_in_future(2))
