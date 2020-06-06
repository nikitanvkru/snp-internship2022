#include <iostream>
#include <string>
using namespace std;


int hours;
int min;
int k;
int i;
int* n = new int[k];
int* f = new int[k];

void AddInfo() {
    cout << "Введите количество записей:\n";
    cin >> k;

    for (int i = 0; i < k; i++) {
        cout << "Введите время начала:\n";
        cin >> hours >> min;
        n[i] = hours * 60 + min;
        cout << "Введите время конца:\n";
        cin >> hours >> min;
        f[i] = hours * 60 + min;
        cout << "Введите содержание заметки" << " " << i << ":\n";
        cin.get();
        string str;
        getline(cin, str);

        if (str.length() > 30) {
            cout << "Строка превышает число возможных символов, введите заново " << "\n";
            while (str.length() > 30)
            {
                getline(cin, str);
            }

        }
    }

}
void Pechat()
{
    for (int i = 420; i < 1395; i++)
    {
        for (int j = 0; j < k; j++) {
            if (i >= n[j] && i <= f[j]) {
                cout << '*';
            }
        }
        cout << i / 60 << ":" << i % 60;
        if (i % 60 == 0)
            cout << "0";
        cout << "\n";

        i = i + 14;

    }

}




int main()
{

    setlocale(LC_ALL, "rus");
    AddInfo();
    Pechat();
    return 0;
}