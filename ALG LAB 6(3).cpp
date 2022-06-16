#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
#include<time.h>
using namespace std;
class BULBSHKA
{
private:
	const int Size= 50000;
	int* mes;
	int* mes1;
	int first, last;
public:
	BULBSHKA()
	{
	    mes = new int[Size];
		mes1 = new int[Size];

	}
	void mesa()
	{
		for (int i = 0; i < Size; i++) {
			mes[Size] = mes1[Size] = (int)rand();
		}

	}
	void Bulbsort()
	{
		int chas;
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size - 1; j++)
			{
				if (mes[j] > mes[j + 1])
				{
					chas = mes[j];
					mes[j] = mes[j + 1];
					mes[j + 1] = chas;
				}
			}
		}

	}
	void sov(int first, int last)
	{
		int m, t;
		int f = first, l = last;
		m = mes[(f + 1) / 2];
		do
		{
			while (mes[f] < m)
				f++;
			while (mes[l] > m)
				l--;
			if (f <= l)
			{
				t = mes[f];
				mes[f] = mes[l];
				mes[l] = t;
				f++;
				l--;
			}
		} while (f < l);
		if (first < l) 
			sov(first, l);
		if (f < last)
			sov(f, last);

	}
	
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int Size = 50000;
	BULBSHKA zviaz;
	zviaz.mesa();
	int first = 0;
	int last = Size - 1;
	clock_t  perb, ostb;
	perb = clock();
	zviaz.Bulbsort();
	ostb = clock();
	printf("Час бульбашкового сортування: %d\n", ostb - perb);
	clock_t  persh, ostsh;
	persh = clock();
	zviaz.sov(first, last);
	ostsh = clock();
	printf("Час швидкого сортування: %d\n", ostsh - persh);
}