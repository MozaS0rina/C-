
#include <iostream>
using namespace std;

// Declaraţii funcţii
void Aranjamente(int k, int n, int ind[], char car[], int m);
void Print(int ind[], char car[], int m);

int main()
{
	int i, N, M, idx[20];
	char sir[20];
	/* Citire sirului de N caractere */
	cout << "Introdu un numar n:";
	cin >> N;

	cout <<"\nIntrodu  n caractere :\n ";
	
	for (i = 0; i < N; i++)
	{
		cout << "sir[" << i + 1 << "]= ";
		cin >> sir[i];
	}
	

		cout<<"\nIntrodu M: ";
		cin >> M;
	
	Aranjamente(0, N, idx, sir, M);

	return 0;
}

void Print(int ind[], char car[], int m)
{
	int i;
	/* Tiparirea caracterelor pe baza indicilor */
	for (i = 0; i < m; i++)
		cout<< car[ind[i]];
	cout << endl;
}

void Aranjamente(int k, int n, int ind[], char car[], int m)
{
	int j;
	
	if (k >= m)
		Print(ind, car, m);
	else
	{ 
		for (j = 0; j < n; j++)
		{
			ind[k] = j;
			Aranjamente(k + 1, n, ind, car, m);
		}
	}
}


