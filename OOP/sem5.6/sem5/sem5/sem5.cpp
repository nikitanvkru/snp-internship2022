#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int convertToMins(int hours, int mins) { return mins + hours * 60; }


void correctOut(int value)
{
    if (value>9)
        cout  << value;
    else cout <<0<< value ;
}

void showTime(int begTime = 0, int stopTime = 5999)
{
    int warnNum,
        errNum,
        comNum;
    

    int endTime,
        time_now;

    time_now = begTime;
    endTime = begTime + 15;

    string s = "";
    cout << "Time" << setw(24) << "Errors" << setw(12) << "Warnings" << setw(10) << "Comments" << endl;

    for (begTime; endTime<=stopTime; )
    {
        warnNum = errNum = comNum = 0;
        if (true)
        {
            ifstream file("data.txt", ios::in);
            if (!file.is_open())
            {
                cout << "Can't open this file";
                return;
            }
            for (getline(file, s); !file.eof(); getline(file, s))
            {
                    time_now = convertToMins((s[0] - '0') * 10 + (s[1] - '0'),
                        (s[3] - '0') * 10 + (s[4] - '0'));

                if (time_now >= begTime && time_now <= endTime)
                {
                    if (s.find("Warning") != string::npos)
                        warnNum++;
                    else if (s.find("Error") != string::npos)
                        errNum++;
                    else if (s.find("Comment") != string::npos)
                        comNum++;
                }
                
            }
            file.seekg(0, ios_base::beg);
        }
  
        
        correctOut(begTime / 60);   cout << ":"; correctOut(begTime % 60); cout << " - ";
        correctOut(endTime / 60);   cout << ":"; correctOut(endTime % 60);
        cout<< setw(10) << errNum << setw(10) << warnNum<< setw(10)<< comNum <<endl;
        begTime += 15;
        endTime += 15;
        
    }


}

int main()
{
    unsigned int inHour, inMin, oHour, oMin;
    fstream datafile;
    datafile.open("data.txt", ios::in);
    input:
    cout << "Enter start hour:";
    cin >> inHour;
    cout << "Enter start min:";
    cin >> inMin;
    cout << "Enter end hour:";
    cin >> oHour;
    cout << "Enter end min:";
    cin >> oMin;

    if (inMin > 60 || oMin > 60 || inHour > 99 || oHour >99 )
        goto input;

    int _begin = convertToMins(inHour, inMin);
    int _end = convertToMins(oHour, oMin);
    showTime(_begin, _end);

    datafile.close();



    return 0;
}