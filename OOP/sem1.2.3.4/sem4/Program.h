#pragma once

#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Class.h"

using namespace std;

class Program
{
private:
	vector<Class> classes;

	void createClass();
	void createSubclass();
	void createMethod();
	void runMethod();
	void showClassesList();
	void showVTable();

	string enterName(const string& ask);
	bool nameCorrect(const string& name);
	bool classExists(const string& name);
	void showError(const string& error);
	void showFunctions();

public:
	void run();
};
