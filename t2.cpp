// t2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string.h>
#pragma warning (disable : 4996)
using namespace std;
int main()
{

	char c[100];
	cout << "Introduceti numele: "<< endl;
	cin.get(c, 99);
	cin.get();
	char s[200];
	int ok = 0,k=0;

	while(ok==0)
	{ 
		cout << "Introduceti sirul nou de caractere: "<< endl ;
		cin.get(s, 199);
		cin.get();
		if (strcmp(c, s) == 0) 
			ok = 1;
		else 
			cout << " Numele nu a fost gasit.Incearca iar!" << endl;
		k++;

	}
	cout << endl;
	cout << "Nume gasit. Ati incercat de " << k  << " ori!";

	

	

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
