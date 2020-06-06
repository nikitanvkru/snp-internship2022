#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <fstream>
#include <stdlib.h>



using namespace std;

class Perem
{
public:
	int Value;
	string Name;
	int Pointer;
	string PSwitch;
	int Cell;
	Perem()     //конструктор
	{
		Value = 0;
		Name = "";
		Pointer = -1;
		PSwitch = "OFF";
		Cell = 0;
	}
	Perem(const Perem & per)
	{
		Value = per.Value;
		Name = per.Name;
		Pointer = per.Pointer;
		PSwitch = per.PSwitch;
		Cell = per.Cell;
	}

int operator=(const Perem & per)
	{
		Value = per.Value;
		Name = per.Name;
		Pointer = per.Pointer;
		PSwitch = per.PSwitch;
		Cell = per.Cell;
			return *this;
	}

	void *operator new(size_t size)
	{
		void * ptr = malloc(size);
		return ptr;
	}
	void operator delete(void* ptr)  {free(ptr);}
	operator int() const  {return Value;}
	~Perem(){}

};

vector<Perem> variable(vector<Perem> avto);
vector<Perem> set(vector<Perem> avto);
vector<Perem> variablePtr(vector<Perem> avto);
vector<Perem> setAddr(vector<Perem> avto);
vector<Perem> setValue(vector<Perem> avto);
vector<Perem> new_(vector<Perem> dynamic);
int new_cont(vector<Perem> dynamic);
vector<Perem> del_avto(vector<Perem> avto);
vector<Perem> del_dynamic(vector<Perem> dynamic);
void print(vector<Perem> avto, vector<Perem> dynamic);
void menu();


int main()
{
	Perem empty;
	vector<Perem> avto(10);
	vector<Perem> dynamic(11);
	int option, delChoice;
	bool flag = true;
	int Adr6;


	while (flag == true)
	{
		menu();
		cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
			avto = variable(avto);
			print(avto, dynamic);
			break;
		case 2:
			avto = set(avto);
			print(avto, dynamic);
			break;
		case 3:
			avto = variablePtr(avto);
			print(avto, dynamic);
			break;
		case 4:
			avto = setAddr(avto);
			print(avto, dynamic);
			break;
		case 5:
			avto = setValue(avto);
			print(avto, dynamic);
			break;
		case 6:
			dynamic = new_(dynamic);
			Adr6 = new_cont(dynamic);
			print(avto, dynamic);
			cout << endl << "Adress of flagged cell:" << endl << Adr6 << endl;
			break;
		case 7:
			cout << "Enter 0 for Automatic Memory or 1 for Dynamic Memory" << endl;
			cin >> delChoice;
			switch (delChoice)
			{
			case 0:
				avto = del_avto(avto);
				break;

			case 1:
				dynamic = del_dynamic(dynamic);
				break;
			}
			print(avto, dynamic);
			break;
		case 8:
			print(avto, dynamic);
			break;
		case 9:
			flag = false;
			break;
		default:
			print(avto, dynamic);
			break;
		}
		
		system("pause");
		system("cls");
	}
}

vector<Perem> variable(vector<Perem> avto) // находит свободное место и размещает там переменную типа int 
{
	string VaR;

	cout << "Enter new variables's name:" << endl;
	cin >> VaR;

	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == VaR)
		{
			cout << "Variable with this name was already created" << endl;
			return avto;
		}
	}

	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == "" && avto[i].Cell == 0)
		{
			avto[i].Cell = 1;
			avto[i].Name = VaR;
			avto[i].PSwitch = "VAR";
			break;
		}
	}

	return avto;

}

vector<Perem> set(vector<Perem> avto) // находит переменную по имени и устанавливает значение
{
	string VaR;
	int Value;
	bool count=false;

	cout << "Enter variable's name:" << endl;
	cin >> VaR;
	cout << "Enter variable's value:" << endl;
	cin >> Value;

	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == VaR)
		{
			count = true;
			avto[i].Value = Value;
		}
	}

	if (count == false)
	{
		cout << "Variable with this name wasn't found";
		return avto;
	}


	
	return avto;
}

vector<Perem> variablePtr(vector<Perem> avto) //находит свободное место в автоматической памяти и размещает там указатель на переменную типа int
{
	string VaR;
	cout << "Enter new pointer's name:" << endl;
	cin >> VaR;

	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == "" && avto[i].Cell == 0)
		{
			avto[i].Cell = 1;
			avto[i].PSwitch = "POINTER";
			avto[i].Name = VaR;
			break;
		}
	}
	return avto;
}

vector<Perem> setAddr(vector<Perem> avto)//находит адрес переменной и заносит его в значение указателя
{
	string VaR;
	string PoI;
	unsigned int NOR;
	bool count = false;

	cout << "Enter variable's name:" << endl;
	cin >> VaR;

	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == VaR)
		{
			count = true;
		}
	}

	if (count == false)
	{
		cout << "Variable with this name wasn't found";
		return avto;
	}

	count = false;


	cout << "Enter pointer's name:" << endl;
	cin >> PoI;



	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == PoI)
		{
			count = true;
		}
	}

	if (count == false)
	{
		cout << "Pointer with this name wasn't found";
		return avto;
	}




	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == VaR)
		{
			NOR = i;
			break;
		}
	}

	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == PoI)
		{
			avto[i].Pointer = NOR;
			break;
		}
	}


	return avto;
}

vector<Perem> setValue(vector<Perem> avto)//разыменовывает указатель и заносит по полученному адресу значение
{
	string PoI;
	bool count;

	cout << "Enter pointer's name:" << endl;
	cin >> PoI;


	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == PoI)
		{
			count = true;
		}
	}

	if (!count)
	{
		cout << "Variable with this name wasn't found";
		return avto;
	}


	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == PoI)
		{ 
			cout << "Enter value:" << endl;
			cin >> avto[avto[i].Pointer].Value;
			count = true;
			break;
		}	
	}
	if(!count)
		cout << "Pointer with this name wasn't found" << endl;

	return avto;
}

vector<Perem> new_(vector<Perem> dynamic)//находит свободный адрес в динамической памяти и занимает его (устанавливает флаг)
{
	for (unsigned int i = 0; i < dynamic.size(); i++)
	{
		if (dynamic[i].Cell == 0)
		{
			dynamic[i].Cell = 1;
			dynamic[10].Pointer = i+10;
			break;
		}
	}
	return dynamic;
}

int new_cont(vector<Perem> dynamic)
{

		int Addr = dynamic[10].Pointer;
		return Addr;
	
}

vector<Perem> del_avto(vector<Perem> avto)
{
	Perem empty;
	string PoI, VaR;
	bool count = false;

	cout << "Enter pointer's name:" << endl;
	cin >> PoI;


	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == PoI)
		{
			count = true;
		}
	}

	if (count == false)
	{
		cout << "Pointer with this name wasn't found";
		return avto;
	}








	for (unsigned int i = 0; i < avto.size(); i++)
	{
		if (avto[i].Name == PoI)
		{
			if (avto[i].Pointer == -1)
			{
				cout << "Pointer does not point";
				return avto;
			}
			else
				avto[avto[i].Pointer] = empty;
			break;


		}
	}
	return avto;
}

vector<Perem> del_dynamic(vector<Perem> dynamic)
{
	Perem empty;
	string PoI;
	bool count=false;

	cout << "Enter pointer's name:" << endl;
	cin >> PoI;

	for (unsigned int i = 0; i < dynamic.size(); i++)
	{
		if (dynamic[i].Name == PoI)
		{
			count = true;
		}
	}

	if (count == false)
	{
		cout << "Pointer with this name wasn't found";
		return dynamic;
	}


	for (unsigned int i = 0; i < dynamic.size(); i++)
	{
		if (dynamic[i].Name == PoI)
		{
			if (dynamic[i].Pointer == -1)
			{
				cout << "Pointer does not point";
				return dynamic;
			}
			dynamic[dynamic[i].Pointer] = empty;
			break;
		}
	}
	return dynamic;
}

void print(vector<Perem> avto, vector<Perem> dynamic)
{
	cout << endl << setw(12) << left << "index" << setw(12) << left << "name" << setw(12) << left << "value" << setw(12) << left << "pointer" << setw(12) << left << "type" << setw(12) << left << "free";
	for (unsigned int i = 0; i < avto.size(); i++)
	{
		cout << endl << setw(12) << left <<i<< setw(12) << left << avto[i].Name << setw(12) << left << avto[i].Value << setw(12) << left << avto[i].Pointer << setw(12) << left << avto[i].PSwitch << setw(12) << left << avto[i].Cell;
	}
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	for (unsigned int i = 0; i < dynamic.size()-1; i++)
	{
		cout << endl << setw(12) << left << i +10<< setw(12) << left << dynamic[i].Name << setw(12) << left << dynamic[i].Value << setw(12) << left << dynamic[i].Pointer << setw(12) << left << dynamic[i].PSwitch << setw(12) << left << dynamic[i].Cell;

	}
	cout << endl;
}

void menu()
{
	cout << endl << "Menu" << endl << "1)Look for a free space and add a null variable" << endl;
	cout << "2)Look for variable's name and set its value" << endl;
	cout << "3)Look for a free space and add a null pointer" << endl;
	cout << "4)Set pointer on variable" << endl;
	cout << "5)Set value by pointer's adress" << endl;
	cout << "6)Set a flag in free dynamic memory" << endl;
	cout << "7)Delete adressed auto or dynamic cell" << endl;
	cout << "8)Print both memory cards" << endl;
	cout << "9)Exit program" << endl;
}