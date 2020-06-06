#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef string CarIdNum;

list <CarIdNum>::iterator findIn(list <CarIdNum> seq, CarIdNum id)
{
    for (list<CarIdNum>::iterator CarIter = seq.begin(); CarIter != seq.end(); ++CarIter)
        if (*CarIter == id)
            return CarIter;

}

int main()
{
    system("cls");
    int path = 0;
    list <CarIdNum> first;
    list <CarIdNum> second;
    list <CarIdNum> third;
    list <CarIdNum> fourth;
    do
    {
        system("cls");
        cout << "Choose the path you'd like to edit/use";
        cout << "\n1)First\n2)Second\n3)Third\n4)Fourth\n5)Exit\n";
        cin >> path;
        list <CarIdNum> *chosen = nullptr;
        int _do = 0;
        switch (path)
        {
        case(1): {chosen = &first; break; }
        case(2): {chosen = &second; break; }
        case(3): {chosen = &third; break; }
        case(4): {chosen = &fourth; break; }
        case(5): {return 0; }
        default: {break; }
        }
        system("cls");
        cout << "What you gonna do with it?:";
        cout << "\n1)Add new element\n2)Remove an item with assigned id\n3)Move element to other path\n";
        cin >> _do;
        switch (_do)
        {
        case(1):
        {
            cout << "Enter personal car number: ";
            CarIdNum newEl;
            cin >> newEl;
            cout << "\n";
            chosen->push_back(newEl);
            for (auto& _id : *chosen)
                std::cout << _id <<endl;
            system("pause");
            break;
        }
        case(2): 
        { 
            cout << "Enter personal car number: ";
            CarIdNum remEl;
            cin >> remEl;
            cout << "\n";
            chosen->remove(remEl);
            for (auto& _id : *chosen)
                std::cout << _id << endl;
            system("pause");
            break;
        }
        case(3): 
        { 
            int path_m = 0;
            list <CarIdNum>* chosen_m = nullptr;
            cout << "Choose the path you'd like to move an element:";
            cout << "\n1)First\n2)Second\n3)Third\n4)Fourth\n";
            cin >> path_m;
            switch (path_m)
            {
            case(1): {chosen_m = &first; break; }
            case(2): {chosen_m = &second; break; }
            case(3): {chosen_m = &third; break; }
            case(4): {chosen_m = &fourth; break; }
            default: {break;}
            }            
            cout << "Enter personal car number you want to move: ";
            CarIdNum movEl;
            cin >> movEl;
            chosen->remove(movEl);
            chosen_m->push_back(movEl);
            cout << "\n";

            cout << "source:\n";
            for (auto& _id : *chosen)
                std::cout << _id << endl;

            cout << "receiver:\n";
            for (auto& _id : *chosen_m)
                std::cout << _id << endl;
            system("pause");
        }
        default: {break; }
        }
    }while (path != 5);

}

