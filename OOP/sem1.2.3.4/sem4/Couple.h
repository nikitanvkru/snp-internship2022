#pragma once

#include <string>

using namespace std;

class Couple
{
private:
	string key, data;

public:
	Couple(const string& key, const string& data);

	string getKey();
	string getData();

	void setData(const string& data);

	bool operator==(const string& value);
};
