#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>

#include "Matrix.h"

using namespace std;

class Program
{
private:
	vector<Matrix> matrices;

	vector<int> enterElements();
	int countNumbers(const string & input);
	int findByName(const string & name);
	bool isNumber(const string & number);
	bool hasSpaces(const string & name);
	string enterName();
	
	void showError(const string & error);
	void showMatrices();
	void showFunctions();
	void M_plus_M(const int & m1, const int & m2, const string & name);
	void M_minus_M(const int & m1, const int & m2, const string & name);
	void M_plus_C(const int & m1, const int & cst, const string & name);
	void M_minus_C(const int & m1, const int & cst, const string & name);

public:
	void run();
};
