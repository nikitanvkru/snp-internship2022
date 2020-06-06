#pragma once

#include <vector>
#include <string>

using namespace std;

class Matrix
{
private:
	int raws, columns;
	vector<vector<int>> elements;
	string name;

public:
	Matrix(const string & name);
	Matrix(const int & raws, const int & columns, const string & name);
	Matrix(const int & identity, const string & name);
	Matrix(vector<int> elements, const string & name);

	int getRaws();
	int getColumns();
	int getElement(const int & i, const int & j);
	string getName();

	void setElement(const int & element, const int & i, const int & j);
};
