#include "Program.h"

string Program::enterName()
{
	string input;

	do
	{
		getline(cin, input);

		if (!hasSpaces(input))
		{
			return input;
		}
		else
		{
			showError("A variable name can't contain spaces");
		}
	} while (_getch() != 0x1B);

	return "";
}

vector<int> Program::enterElements()
{
	vector<int> elements;
	char buffer[64], * number;
	string input;

	do
	{
		getline(cin, input);

		switch (countNumbers(input))
		{
		case 9:
			strcpy(buffer, input.c_str());
			number = strtok(buffer, " ");
			while (number != nullptr)
			{
				elements.push_back(atoi(number));
				number = strtok(nullptr, " ");
			}
			return elements;
		case -1:
			showError("Empty input");
			break;
		case -2:
			showError("Only digits required");
			break;
		default:
			showError("Only 9 numbers required");
			break;
		}
	} while (_getch() != 0x1B);

	return elements;
}

int Program::countNumbers(const string & input)
{
	int numbers = 0;
	char buffer[64], * number;
	string sendNumber;

	if (input.empty())
	{
		return -1;
	}

	strcpy(buffer, input.c_str());
	number = strtok(buffer, " ");
	while (number != nullptr)
	{
		sendNumber = number;
		if (!isNumber(sendNumber))
		{
			return -2;
		}
		number = strtok(nullptr, " ");
		numbers++;
	}

	return numbers;
}

int Program::findByName(const string & name)
{
	int size = matrices.size();

	for (int i = 0; i < size; i++)
	{
		if (matrices[i].getName() == name)
		{
			return i;
		}
	}

	return -1;
}

bool Program::isNumber(const string & number)
{
	int size = number.size();

	for (int i = 0; i < size; i++)
	{
		if (!isdigit(number[i]))
		{
			return false;
		}
	}

	return true;
}

bool Program::hasSpaces(const string & name)
{
	int size = name.size();

	for (int i = 0; i < size; i++)
	{
		if (name[i] == ' ')
		{
			return true;
		}
	}

	return false;
}

void Program::showError(const string & error)
{
	cout << "ERROR: " << error << endl;
	system("pause");
}

void Program::showMatrices()
{
	system("cls");

	int size = matrices.size();
	int raws, columns;

	for (int i = 0; i < size; i++)
	{
		cout << matrices[i].getName() << " : ";

		raws = matrices[i].getRaws();
		columns = matrices[i].getColumns();
		for (int j = 0; j < raws; j++)
		{
			for (int k = 0; k < columns; k++)
			{
				cout << matrices[i].getElement(j, k) << " ";
			}
		}
		cout << endl;
	}

	do
	{
	} while (_getch() != 0x1B);
}

void Program::showFunctions()
{
	system("cls");
	cout << "1. Create 3D zero matrix" << endl
		<< "2. Create 2D zero matrix" << endl
		<< "3. Create 2D identity matrix" << endl
		<< "4. Create 3D matrix" << endl
		<< "5. Sum 2 matrices" << endl
		<< "6. Subtract 2 matrices" << endl
		<< "7. Add matrix and number" << endl
		<< "8. Subtract number from matrix" << endl
		<< "9. Show matrices" << endl;
}

void Program::M_plus_M(const int & m1, const int & m2, const string & name)
{
	int raws = matrices[m1].getRaws(), columns = matrices[m1].getColumns();
	switch (raws)
	{
	case 3:
		matrices.push_back(Matrix(name));
		break;
	case 2:
		matrices.push_back(Matrix(2, 2, name));
		break;
	}
	
	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrices.back().setElement(matrices[m1].getElement(i, j) + matrices[m2].getElement(i, j), i, j);
		}
	}
}

void Program::M_minus_M(const int & m1, const int & m2, const string & name)
{
	int raws = matrices[m1].getRaws(), columns = matrices[m1].getColumns();
	switch (raws)
	{
	case 3:
		matrices.push_back(Matrix(name));
		break;
	case 2:
		matrices.push_back(Matrix(2, 2, name));
		break;
	}

	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrices.back().setElement(matrices[m1].getElement(i, j) - matrices[m2].getElement(i, j), i, j);
		}
	}
}

void Program::M_plus_C(const int & m1, const int & cst, const string & name)
{
	int raws = matrices[m1].getRaws(), columns = matrices[m1].getColumns();
	switch (raws)
	{
	case 3:
		matrices.push_back(Matrix(name));
		break;
	case 2:
		matrices.push_back(Matrix(2, 2, name));
		break;
	}

	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrices.back().setElement(matrices[m1].getElement(i, j) + cst, i, j);
		}
	}
}

void Program::M_minus_C(const int & m1, const int & cst, const string & name)
{
	int raws = matrices[m1].getRaws(), columns = matrices[m1].getColumns();
	switch (raws)
	{
	case 3:
		matrices.push_back(Matrix(name));
		break;
	case 2:
		matrices.push_back(Matrix(2, 2, name));
		break;
	}

	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrices.back().setElement(matrices[m1].getElement(i, j) - cst, i, j);
		}
	}
}

void Program::run()
{
	int m1, m2;
	char key;
	vector<int> elements;
	string name, number;

	do
	{
		showFunctions();
		key = _getch();

		switch (key)
		{
		case 0x31:
			cout << "Enter a matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				matrices.push_back(Matrix(name));
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x32:
			cout << "Enter a matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				matrices.push_back(Matrix(2, 2, name));
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x33:
			cout << "Enter a matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				matrices.push_back(Matrix(1, name));
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x34:
			cout << "Enter a matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				cout << "Enter its elements" << endl;
				elements = enterElements();
				if (!elements.empty())
				{
					matrices.push_back(Matrix(elements, name));
				}
			}
			break;

		case 0x35:
			cout << "Enter first matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				m1 = findByName(name);
			}
			else
			{
				showError("Empty input");
				break;
			}
			if (m1 == -1)
			{
				showError("There is no matrix with this name");
				break;
			}

			cout << "Enter second matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				m2 = findByName(name);
			}
			else
			{
				showError("Empty input");
				break;
			}
			if (m2 == -1)
			{
				showError("There is no matrix with this name");
				break;
			}

			if (matrices[m1].getRaws() != matrices[m2].getRaws() || matrices[m1].getColumns() != matrices[m2].getColumns())
			{
				showError("These matrices have different number of raws or columns");
				break;
			}

			cout << "Enter result matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				M_plus_M(m1, m2, name);
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x36:
			cout << "Enter first matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				m1 = findByName(name);
			}
			else
			{
				showError("Empty input");
				break;
			}
			if (m1 == -1)
			{
				showError("There is no matrix with this name");
				break;
			}

			cout << "Enter second matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				m2 = findByName(name);
			}
			else
			{
				showError("Empty input");
				break;
			}
			if (m2 == -1)
			{
				showError("There is no matrix with this name");
				break;
			}

			if (matrices[m1].getRaws() != matrices[m2].getRaws() || matrices[m1].getColumns() != matrices[m2].getColumns())
			{
				showError("These matrices have different number of raws or columns");
				break;
			}

			cout << "Enter result matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				M_minus_M(m1, m2, name);
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x37:
			cout << "Enter matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				m1 = findByName(name);
			}
			else
			{
				showError("Empty input");
				break;
			}
			if (m1 == -1)
			{
				showError("There is no matrix with this name");
				break;
			}

			cout << "Enter a number" << endl;
			getline(cin, number);
			number.erase(remove(number.begin(), number.end(), ' '), number.end());

			if (isNumber(number))
			{
				m2 = stoi(number);
			}
			else
			{
				showError("The constant isn't a number");
				break;
			}

			cout << "Enter result matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				M_plus_C(m1, m2, name);
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x38:
			cout << "Enter matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				m1 = findByName(name);
			}
			else
			{
				showError("Empty input");
				break;
			}
			if (m1 == -1)
			{
				showError("There is no matrix with this name");
				break;
			}

			cout << "Enter a number" << endl;
			getline(cin, number);
			number.erase(remove(number.begin(), number.end(), ' '), number.end());

			if (isNumber(number))
			{
				m2 = stoi(number);
			}
			else
			{
				showError("The constant isn't a number");
				break;
			}

			cout << "Enter result matrix name:" << endl;
			name = enterName();
			if (!name.empty())
			{
				M_minus_C(m1, m2, name);
			}
			else
			{
				showError("Empty input");
			}
			break;

		case 0x39:
			showMatrices();
			break;
		}
	} while (key != 0x1B);
}
