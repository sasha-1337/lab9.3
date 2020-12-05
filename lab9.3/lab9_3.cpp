#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

struct Price
{
	string nameTowar;
	string shop;
	int cost;
};

void Create(Price* p, const int N);
void Print(Price* p, const int N);
int BinSearch(Price* p, const int N, const string nameTowar);
void PrintSearch(Price* p, const int Num);
void Sort(Price* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << " Введіть кількість товару: "; cin >> N;
	Price* p = new Price[N];

	string shop;
	string nameTowar;
	int found;

	int MenuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [4] - бінарний пошук товару за назвою" << endl;
		cout << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> MenuItem;
		cout << endl << endl << endl;

		switch (MenuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			cout << "Введіть ключі пошуку:" << endl;
			cin.get();
			cin.sync();
			cout << "Назва товару: "; getline(cin, nameTowar);
			cout << endl;
			if ((found = BinSearch(p, N, nameTowar)) != -1) {
				cout << "Ось, товар, який ви шукали! \n";
				PrintSearch(p, found + 1);
			}
			else
				cout << "Товар не знайдено" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (MenuItem != 0);
	return 0;
}

void Create(Price* p, const int N)
{
	int shop;
	for (int i = 0; i < N; i++) {
		cout << " Товар № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Назва магазину: "; getline(cin, p[i].shop);
		
		cout << " Назва товару: "; getline(cin, p[i].nameTowar);
		
		cout << " Ціна: "; cin >> p[i].cost;
		cout << endl << endl;
	}
}

void Print(Price* p, const int N) 
{
	cout << "=========================================================="
		<< endl;
	cout << "|  №  |     Магазин     |      Товар      |     Ціна     |"
		<< endl;
	cout << "=========================================================="
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << p[i].shop
			<< "| " << setw(16) << left << p[i].nameTowar
			<< "| " << setw(12) << right << setprecision(2) << p[i].cost << " |";
		cout << endl;
		cout << "----------------------------------------------------------";
		cout << endl;
	}
}

int BinSearch(Price* p, const int N, const string nameTowar)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].nameTowar == nameTowar)
			return m;

		if (p[m].nameTowar < nameTowar)
			L = m + 1;

		else 
			R = m - 1;
		
	} while (L <= R);
	return -1;
}

void PrintSearch(Price* p, const int Num) 
{
	cout << "=========================================================="
		<< endl;
	cout << "|  №  |     Магазин     |      Товар      |     Ціна     |"
		<< endl;
	cout << "----------------------------------------------------------"
		<< endl;

	cout << "| " << setw(3) << right << Num << " ";
	cout << "| " << setw(16) << left << p[Num].shop
		<< "| " << setw(16) << left << p[Num].nameTowar
		<< "| " << setw(12) << right << setprecision(2) << p[Num].cost << " |";
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}

void Sort(Price* p, const int N) 
{
	Price tmp;
	for (int i = 0; i < N-1; i++) // метод "бульбашки"
		for (int j = 0; j < N-i-1; j++)
			if (p[j].shop > p[j + 1].shop) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
}