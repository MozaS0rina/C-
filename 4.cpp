
#include <iostream>
#include<string.h>
#include<conio.h>


using namespace std;




// Declaraţii funcţii
#define M 5

int i;

struct st
{
	char s[10];
};

struct st student[10];


void afisarestud(int ind[], struct st* car, int m)
{
	/* Tiparirea strudentilor pe baza indicilor */
	int x = ind[i];
	for (i = 0; i < m; i++)
		cout << car[x].s << " ";
	cout << endl;
}

void Aranjamente(int k, int n, int ind[], struct st &car, int m)
{
	int j;

	if (k >= m) 
		afisarestud(ind, &car, m);
	else
	{
		for (j = 0; j < n; j++)
		{
			ind[k] = j;
			Aranjamente(k + 1, n, ind, car, m);
		}
	}
}


int main()
{
	int i, N,  idx[20];
	
	/* Citire sirului de N caractere */
	cout << "Introdu un numar n (>5 ):";
	cin >> N;

	cout << "\nIntrodu  cei n studenti :\n ";

	for (i = 0; i < N; i++)
	{
		cout << "student # "<< i + 1 << "= ";
		cin>>student[i].s;
	}



	Aranjamente(0, N, idx, *student, M);

	return 0;
}



