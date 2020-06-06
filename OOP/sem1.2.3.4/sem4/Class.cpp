#include "Class.h"

string Class::getName()
{
	return name;
}

string Class::getParent()
{
	return parent;
}

vector<Couple> Class::getMethods()
{
	return methods;
}

bool Class::addMethod(const string& method, const string& parent)
{
	if (methods.end() == find(methods.begin(), methods.end(), method))
	{
		methods.push_back(Couple(method, parent));
		return true;
	}
	return false;
}

void Class::runMethod(const string& method)
{
	if (methods.end() != find(methods.begin(), methods.end(), method))
	{
		system("cls");
		cout << "Class " + name << endl << method << "\n{\n...\n}" << endl;
	}
	else
	{
		cout << "ERROR: This method doesn't exist" << endl;
	}
	system("pause");
}

void Class::showVTable()
{
	vector<string> vptr;

	for_each(begin(methods), end(methods), [&vptr](Couple& str) {vptr.push_back(str.getData()); });
	sort(vptr.begin(), vptr.end());
	auto last = unique(begin(vptr), end(vptr));
	vptr.erase(last, vptr.end());

	vector<vector<Couple>> vTable;
	vTable.resize(vptr.size());

	for (size_t i = 0; i < vptr.size(); i++)
	{
		copy_if(methods.begin(), methods.end(), back_inserter(vTable[i]), [vptr, i](Couple& str) {return str.getData() == vptr[i]; });
	}

	system("cls");
	cout << "Class " << name << endl << endl;
	for (auto i : vTable)
	{
		cout << "vTable " + name;
		if (!i[0].getData().empty())
		{
			cout << " (" + i[0].getData() + ")";
		}
		cout << endl;

		for (Couple j : i)
		{
			cout << j.getKey() << endl;
		}
		cout << endl;
	}
	system("pause");
}

bool Class::operator==(const Class& another)
{
	return name == another.name;
}

Class::Class(const string& name, const string& parent)
{
	this->name = name;
	this->parent = parent;
}

Class::Class(const string& name, const string& parent, vector<Couple> methods)
{
	this->name = name;
	this->parent = parent;

	for (Couple &it : methods)
	{
		if (it.getData().empty())
		{
			it.setData(parent);
		}
	}
	copy(methods.begin(), methods.end(), back_inserter(this->methods));
}
