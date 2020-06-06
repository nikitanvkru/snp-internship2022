#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Couple.h"

using namespace std;

class Class
{
private:
	string name, parent;
	vector<Couple> methods;

public:
	string getName();
	string getParent();
	vector<Couple> getMethods();

	bool addMethod(const string& method, const string& parent);
	void runMethod(const string& method);
	void showVTable();

	bool operator==(const Class& another);

	Class(const string& name, const string& parent);
	Class(const string& name, const string& parent, vector<Couple> methods);
};
