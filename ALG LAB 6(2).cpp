#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include <iomanip>
#include<Windows.h>
using namespace std;
int f, l; 
const int Size = 4;
struct INF
{
	int key;
	char info[156];
};
INF struk[Size];
void Sort(int first, int last)
{
	int mid;
	INF t;
	int f = first, l = last;
	mid = struk[(f + l) / 2].key;
	do
	{
		while (struk[f].key < mid) f++;
		while (struk[l].key > mid) l--;
		if (f <= l)
		{
			t.key = struk[f].key;
			*t.info = *struk[f].info;
			struk[f].key = struk[l].key;
			*struk[f].info = *struk[l].info;
			struk[l].key = t.key;
			*struk[l].info = *t.info;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) Sort(first, l);
	if (f < last) Sort(f, last);
}

void mes() 
{
	srand(1);
	for(int i=0;i< Size;i++)
	{
		cout << "Введіть номер ключа - " << endl;
		cin >> struk[i].key;
		cin.ignore();
		cout << "Введіть інформацію - " << endl;
		gets_s(struk[i].info);

	}
}
void PRINT()
{
	for(int i=0;i< Size;i++){
	cout << struk[i].key << ". ";
	cout << struk[i].info << endl;
}
}

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	f = 0; 
	l = Size - 1;
	mes();
	cout << "Ваша структура - " << endl;
	PRINT();
	cout << endl;
	cout << "Відсортована структура - " << endl;
	Sort(f, l);
	PRINT();

}
