// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int s,k;
void suma(int k, int n , int a[])
{
	if (k < n)
	{
		s = s + a[k];
		suma(k + 1, n, a);
	}


}

int main()
{
	int n, a[100];
	cout << "Introduceti o valoare n:\n ";
	cin >> n;
	cout << "Dati un vector cu n elemente: \n ";
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];
	cout << "\n Elementele vectorului sunt: ";
	for (i = 0; i < n; i++)
		cout <<a[i]<<"  ";
	cout << endl;
	suma(k,n,a);
	cout << endl;
	cout << "Suma elementelor vectorului este: " << s<<endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
