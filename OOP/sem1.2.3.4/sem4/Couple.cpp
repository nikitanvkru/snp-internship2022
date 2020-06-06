#include "Couple.h"

Couple::Couple(const string& key, const string& data)
{
	this->key = key;
	this->data = data;
}

string Couple::getKey()
{
	return key;
}

string Couple::getData()
{
	return data;
}

void Couple::setData(const string& data)
{
	this->data = data;
}

bool Couple::operator==(const string& value)
{
	return key == value;
}
