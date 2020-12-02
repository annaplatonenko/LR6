// Лабораторная работа №6
// Вариант 5
// Реализовать базовый класс(указан в варианте) и унаследовать от него 2 производных класса(обозначим их D1 и D2 для простоты), 
// которые будут являться "подкатегориями" базового класса.
// В эти дочерние классы добавить необходимые соответствующие поля и методы.
// От производных классов(от D1 и D2) унаследовать один общий для них производный класс(D12).
// В производных классах D1 и D2 по - разному переопределить унаследованный метод от базового класса, 
// а в классе D12 этот метод не переопределять.
// Инициализация полей базового класса при создании объекта дочернего класса должна реализоваться через вызов конструктора базового класса.
// Реализовать возможность просмотра содержимого.Продемонстрировать работу всех методов класса D12.
// Все производные классы(D1, D2, D12) добавляют по 2 - 3 поля и по 2 - 3 метода.
// Все возможные данные вводятся с клавиатуры с проверкой на корректность.
// Данные для объектов вводятся в main и передаются в объекты классов через конструкторы.
// Память выделять динамически.В случае отсутствия надобности в дальнейшем использовании выделенной памяти осуществлять освобождение памяти.


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
			cout << "Некорректный ввод!!! Повторите ...\n";
			cout << "Введите " << n << ':';
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
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "пляж " << getbeach() << endl << endl;
	}

	void vvod() override
	{
		cout << endl << "Beach_Football" << endl;
		cout << "введите количество игроков: ";
		*number_players = proverka("количество игроков");
		cout << "введите размер поля: ";
		*field_size = proverka("размер поля");
		cout << "введите пляж: ";
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
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "стадион " << getstadium() << endl;
		cout << "название команды " << getteam_name() << endl;
	}

	void vvod() override
	{
		cout << endl << "Rugby_Football" << endl;
		int buf;
		cout << "введите количество игроков: ";
		*number_players = proverka("количество игроков");
		cout << "введите размер поля: ";
		*field_size = proverka("размер поля");
		cout << "введите стадион: ";
		cin >> *stadium;
		cout << "введите название команды: ";
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
		cout << "количество игроков " << getnumberplayers() << endl;
		cout << "размер поля " << getfieldsize() << endl;
		cout << "пляж " << getbeach() << endl;
		cout << "стадион " << getstadium() << endl;
		cout << "название команды " << getteam_name() << endl;
		cout << "название цвета " << *color << endl;
	}

	void vvod() override
	{
		cout << endl << "My_Football" << endl;
		cout << "введите количество игроков: ";
		*number_players = proverka("количество игроков");
		cout << "введите размер поля: ";
		*field_size = proverka("размер поля");
		cout << "введите пляж: ";
		cin >> *beach;
		cout << "введите стадион: ";
		cin >> *stadium;
		cout << "введите название команды: ";
		cin >> *team_name;
		cout << "введите название цвета: ";
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

