#include<iostream>
#include<math.h>
#include<ctime>
#include<Windows.h>

using namespace std;
class ZMVYB
{
private:
	int* mass;
	int size = 10;
public:
	ZMVYB()
	{
		srand(time(0));
		mass = new int[size];
	}
	void PRINT() {
		cout << "Ваш массив - (";
		for (int i = 0; i < size; i++)
		{
			cout << mass[i] << " ";
		}
		cout << ")" << endl;
	}
	void rozm()
	{
		for (int i = 0; i < size; i++)
		{
			mass[i] = rand() % 70 - 35;
		}
	}
void vybir()
	{
		int minind, minkey;
		for (int i = 0; i < (size - 1); i++)
		{
			minind = i;
			minkey = mass[i];
			for (int j = i + 1; j < size; j++)

				if (mass[j] < minkey)
				{
					minkey = mass[j];
					minind = j;
				}
			swap(mass[i], mass[minind]);

		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ZMVYB zvyaz;
	zvyaz.rozm();
	zvyaz.vybir();
	zvyaz.PRINT();
}