#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

typedef int inform;
struct Spusok
{
	Spusok* link;
	inform inf;
};

void Start_1(Spusok*& first, Spusok*& last, inform i);
int Start_0(ifstream& file_load, Spusok*& first, Spusok*& last);
void Print(Spusok*& first, Spusok*& T, const int N);
int process(Spusok*& T, Spusok*& first_1, Spusok*& last_1);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	Spusok* first_1 = NULL;
	Spusok* last_1 = NULL;

	char fname[51];
	cout << "Введіть назву файлу для зчитування слів: "; cin >> fname; cout << endl;

	bool bol;
	cout << "Введіть '1' або '2': " << endl << endl;
	cout << "1 - формування однозв’язний список за допомогою введені даних з клавіатури" << endl;
	cout << "0 - формування однозв’язний список за допомогою зчитування з текстового файлу" << endl << endl;
	cout << "Введіть: "; cin >> bol; cout << endl;

	int kilkist;
	inform value;
	if (bol)
	{
		cout << "Введіть певну кількість елементів(значення цілочисельне): "; cin >> kilkist; cout << endl;
		for (int i = 0; i < kilkist; i++)
		{
			cout << "№" << i + 1 << "  "; cin >> value;
			Start_1(first, last, value);
		}
	}
	else
	{
		ifstream file_load;
		file_load.open(fname);
		kilkist = Start_0(file_load, first, last);
		file_load.close();
	}

	cout << "Сформована черга за допомогою зчитування з текстового файлу: " << endl << endl;
	Spusok* T = first;
	Print(first, T, kilkist);

	cout << "Сформована черга з чисел які є квадратами і кубами чисел: " << endl << endl;
	T = first;
	int kil_pro = process(T, first_1, last_1);

	T = first_1;
	Print(first_1, T, kil_pro);

	return 0;
}

void Start_1(Spusok*& first, Spusok*& last, inform i)
{
	Spusok* tmp = new Spusok;
	tmp->inf = i;
	tmp->link = NULL;
	if (first == NULL)
		first = tmp;
	else
		last->link = tmp;
	last = tmp;
}

int Start_0(ifstream& file_load, Spusok*& first, Spusok*& last)
{
	inform i;
	int kilkist = 0;

	while (!file_load.eof())
	{
		file_load >> i;
		Spusok* tmp = new Spusok;
		tmp->inf = i;
		tmp->link = NULL;
		if (first == NULL)
			first = tmp;
		else
			last->link = tmp;
		last = tmp;
		kilkist++;
	}
	return kilkist;
}

void Print(Spusok*& first, Spusok*& T, const int N)
{
	inform i;
	int index = 0;

	while (index < N)
	{
		i = T->inf;
		cout << i << "   ";
		T = T->link;
		index++;
	}
	cout << endl << endl;
}

int process(Spusok*& T, Spusok*& first_1, Spusok*& last_1)
{
	double value;
	double x, y;
	int kil = 0;

	while (T != NULL)
	{
		value = T->inf;                       // 1(змінна 'value' отримує значення від елемента списка)

		x = pow(value, 1.0 / 2.0);            // 2(змінна 'x' отримує значення(завдяки піднесенню змінної 'value' до степеня))
		y = pow(value, 1.0 / 3.0);            // 3(змінна 'y' отримує значення(завдяки піднесенню змінної 'value' до степеня)

		if (x == (int)x || y == (int)y) 
		{
			Start_1(first_1, last_1, value);  // 4(створився новостворений список і добавився елемент до даного списку)
			kil++;                            // 5(змінна 'kil' збільшилася на одницю)
		}

		T = T->link;                          // 6(вказівник перейшов до наступної позиції)
	}
	return kil;
}