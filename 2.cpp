#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

using namespace std;

#define n 5

char m[n + 1][n + 1][n + 1];

int i, j, k;

div_t a, b, c;
int o[10],o1,ok ,op;

void tipar()

{

	for (i = 0; i <= n; i++)

	{


		for (j = 0; j <= n; j++)

		{
			for (k = 0; k <= n; k++)

				cout << m[i][j][k] << "  ";

			cout << endl;
		}
		cout << endl;
	}

	cout << "\n";

}

void p(int x, int y, int q)

{

	if (m[x][y][q] == ' ')

	{

		m[x][y][q] = '+';
		op++;

		a = div(x, n);

		b = div(y, n);

		c = div(q, n);

		if ((a.rem == 0) || (b.rem == 0) || (c.rem == 0))

		{
			tipar();
			o[o1] = op;
			op = 0;
		}

		else

		{

			p(x + 1, y,q);
			p(x + 1, y, q+1);

			p(x, y + 1,q);
			p(x, y + 1, q+1);

			p(x - 1, y,q);
			p(x - 1, y,q-1);

			p(x, y - 1,q);
			p(x, y - 1,q-1);
		}

		m[x][y][q] = ' ';

	}

}

int main()

{

	for (i = 0; i <= n; i++)

		for (j = 0; j <= n; j++)

			for (k = 0; k <= n; k++)

			m[i][j][k] = '*';

	for (j = 2; j <= 5; j++)

		m[1][j][3] = ' ';

	m[0][0][1] = ' ';

	m[0][0][2] = ' ';
	
	m[2][0][1] = ' ';

	m[1][2][0] = ' ';

	m[1][3][0] = ' ';

	m[1][3][1] = ' ';

	m[2][1][1] = ' ';

	m[2][4][2] = ' ';

	m[1][4][1] = ' ';

	m[4][0][1] = ' ';

	m[3][2][3] = ' ';

	m[3][3][3] = ' ';

	m[3][4][1] = ' ';

	m[4][2][3] = ' ';

	m[5][2][2] = ' ';

	m[1][1][2] = ' ';

	m[1][2][3] = ' ';

	m[2][2][1] = ' ';

	m[3][2][1] = ' ';

	m[3][2][3] = ' ';

	m[3][2][4] = ' ';

	m[4][1][1] = ' ';

	

	tipar();

	a = div(n, 2);

	p(a.quot, a.quot,a.quot);

	int max;
	max = o[0];

	for (i = 1; i < o1; i++)
	{
		if (max < o[i])
			max = o[i];
	}
	cout << "Cea mai optima iesire din labirint este din: " << max << " miscari";
	cout << endl;
	cout << "\nCompletarea labirintului a fost realizata manual. Pentru modificari, reveniti la cod!\n";
}