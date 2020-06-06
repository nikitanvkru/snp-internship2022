#include "Matrix.h"
#include "string"
Matrix::Matrix(const string & name)
{
	this->name = name;
	raws = columns = 3;
	elements.push_back({0,0,0});
	elements.push_back({0,0,0});
	elements.push_back({0,0,0});
}

Matrix::Matrix(const int & raws, const int & columns, const string & name)
{
	this->name = name;
	this->raws = raws;
	this->columns = columns;
	vector<int> zeros(columns, 0);
	for (int i = 0; i < raws; i++)
	{
		elements.push_back(zeros);
	}
}

Matrix::Matrix(const int & identity, const string & name)
{
	this->name = name;
	raws = columns = 2;
	elements.push_back({0, 0});
	elements.push_back({0, 0});
	elements[0][0] = identity;
	elements[1][1] = identity;
}

Matrix::Matrix(vector<int> elements, const string & name)
{
	this->name = name;
	raws = columns = 3;
	this->elements.push_back({elements[0], elements[1], elements[2]});
	this->elements.push_back({elements[3], elements[4], elements[5]});
	this->elements.push_back({elements[6], elements[7], elements[8]});
}

int Matrix::getRaws()
{
	return raws;
}

int Matrix::getColumns()
{
	return columns;
}

int Matrix::getElement(const int & i, const int & j)
{
	return elements[i][j];
}

string Matrix::getName()
{
	return name;
}

void Matrix::setElement(const int & element, const int & i, const int & j)
{
	elements[i][j] = element;
}
