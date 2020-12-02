// ������������ ������ �6
// ������� 5
// ����������� ������� �����(������ � ��������) � ������������ �� ���� 2 ����������� ������(��������� �� D1 � D2 ��� ��������), 
// ������� ����� �������� "��������������" �������� ������.
// � ��� �������� ������ �������� ����������� ��������������� ���� � ������.
// �� ����������� �������(�� D1 � D2) ������������ ���� ����� ��� ��� ����������� �����(D12).
// � ����������� ������� D1 � D2 �� - ������� �������������� �������������� ����� �� �������� ������, 
// � � ������ D12 ���� ����� �� ��������������.
// ������������� ����� �������� ������ ��� �������� ������� ��������� ������ ������ ������������� ����� ����� ������������ �������� ������.
// ����������� ����������� ��������� �����������.������������������ ������ ���� ������� ������ D12.
// ��� ����������� ������(D1, D2, D12) ��������� �� 2 - 3 ���� � �� 2 - 3 ������.
// ��� ��������� ������ �������� � ���������� � ��������� �� ������������.
// ������ ��� �������� �������� � main � ���������� � ������� ������� ����� ������������.
// ������ �������� �����������.� ������ ���������� ���������� � ���������� ������������� ���������� ������ ������������ ������������ ������.


#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Football
{
protected:
	int* number_players;
	int* field_size;

public:

	Football(int number_players = 0, int field_size = 0)
	{
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
	}

	~Football()
	{
		delete number_players;
		delete field_size;
	}

	virtual int getnumberplayers()
	{
		return *number_players;
	}

	virtual int getfieldsize()
	{
		return *field_size;
	}

	virtual void printall() = 0;
	virtual void vvod() = 0;

	virtual int proverka(string n)
	{
		int buf;
		while (!(cin >> buf))
		{
			cout << "������������ ����!!! ��������� ...\n";
			cout << "������� " << n << ':';
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		return buf;
	}
};

class Beach_Football : public virtual Football
{
protected:
	string* beach;

public:
	Beach_Football(int number_players = 0, int field_size = 0, string beach = "no name") : Football()
	{
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
		this->beach = new string(beach);
	}

	~Beach_Football()
	{
		delete beach;
	}

	string getbeach()
	{
		return *beach;
	}

	void printall() override
	{
		cout << "Beach_Football" << endl;
		cout << "���������� ������� " << getnumberplayers() << endl;
		cout << "������ ���� " << getfieldsize() << endl;
		cout << "���� " << getbeach() << endl << endl;
	}

	void vvod() override
	{
		cout << endl << "Beach_Football" << endl;
		cout << "������� ���������� �������: ";
		*number_players = proverka("���������� �������");
		cout << "������� ������ ����: ";
		*field_size = proverka("������ ����");
		cout << "������� ����: ";
		cin >> *beach;
	}
};

class Rugby_Football : public virtual Football
{
protected:
	string* stadium;
	string* team_name;

public:
	Rugby_Football(int number_players = 0, int field_size = 0, string stadium = "no name", string team_name = "no name") : Football()
	{
		this->number_players = new int(number_players);
		this->field_size = new int(field_size);
		this->stadium = new string(stadium);
		this->team_name = new string(team_name);
	}

	~Rugby_Football()
	{
		delete stadium;
		delete team_name;
	}

	int getnumberplayers() override
	{
		return *number_players;
	}

	int getfieldsize() override
	{
		return *field_size;
	}

	string getstadium()
	{
		return *stadium;
	}

	string getteam_name()
	{
		return *team_name;
	}

	void printall() override
	{
		cout << "Rugby_Football" << endl;
		cout << "���������� ������� " << getnumberplayers() << endl;
		cout << "������ ���� " << getfieldsize() << endl;
		cout << "������� " << getstadium() << endl;
		cout << "�������� ������� " << getteam_name() << endl;
	}

	void vvod() override
	{
		cout << endl << "Rugby_Football" << endl;
		int buf;
		cout << "������� ���������� �������: ";
		*number_players = proverka("���������� �������");
		cout << "������� ������ ����: ";
		*field_size = proverka("������ ����");
		cout << "������� �������: ";
		cin >> *stadium;
		cout << "������� �������� �������: ";
		cin >> *team_name;
	}
};

class My_Football : public Beach_Football, public Rugby_Football
{
public:
	string* color;

	My_Football()
	{
		color = new string();
	}

	~My_Football()
	{
		delete color;
	}

	void printall() override
	{
		cout << "My_Football" << endl;
		cout << "���������� ������� " << getnumberplayers() << endl;
		cout << "������ ���� " << getfieldsize() << endl;
		cout << "���� " << getbeach() << endl;
		cout << "������� " << getstadium() << endl;
		cout << "�������� ������� " << getteam_name() << endl;
		cout << "�������� ����� " << *color << endl;
	}

	void vvod() override
	{
		cout << endl << "My_Football" << endl;
		cout << "������� ���������� �������: ";
		*number_players = proverka("���������� �������");
		cout << "������� ������ ����: ";
		*field_size = proverka("������ ����");
		cout << "������� ����: ";
		cin >> *beach;
		cout << "������� �������: ";
		cin >> *stadium;
		cout << "������� �������� �������: ";
		cin >> *team_name;
		cout << "������� �������� �����: ";
		cin >> *color;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int size = 3;

	Football** massiv = new Football * [size];
	My_Football* my = new My_Football();
	Beach_Football* beach = new Beach_Football();
	Rugby_Football* rugby = new Rugby_Football();

	massiv[0] = my;
	massiv[1] = beach;
	massiv[2] = rugby;

	for (int i = 0; i < 1; i++)
	{
		massiv[i]->vvod();
	}
	cout << endl;

	for (int i = 0; i < 1; i++)
	{
		massiv[i]->printall();
	}
	cout << endl;

	delete my;
	delete beach;
	delete rugby;
}

