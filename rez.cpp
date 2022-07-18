#include <iostream>

#include <conio.h>

#include <stdio.h>

#pragma warning (disable:4996)

using namespace std;

FILE* sursa, * dest, * a, * b;

char ch;

int file_size = 0, a_size = 0, b_size = 0;

void transfera_sursa_in_destinatie()

{

	sursa = fopen("sursa.txt", "rt");

	dest = fopen("dest.txt", "wt");

	while (!feof(sursa))

	{

		ch = fgetc(sursa);

		if (!feof(sursa))

		{

			fputc(ch, dest);

			file_size++;

		}

	}

	fclose(sursa);

	fclose(dest);

}

void split_destinatie(int nr)

{

	int ch_scrise = 0;

	dest = fopen("dest.txt", "rt");

	a = fopen("a.tmp", "wt");

	b = fopen("b.tmp", "wt");

	a_size = 0; b_size = 0;

	while (ch_scrise < file_size)

	{

		int i;

		for (i = 1; ((i <= nr) && (ch_scrise < file_size)); i++)

		{

			ch = fgetc(dest);

			fputc(ch, a);

			a_size++;

			ch_scrise++;

		}

		for (i = 1; ((i <= nr) && (ch_scrise < file_size)); i++)

		{

			ch = fgetc(dest);

			fputc(ch, b);

			b_size++;

			ch_scrise++;

		}

	}

	fclose(dest);

	fclose(a);

	fclose(b);

}

void interclaseaza(int nr)

{

	a = fopen("a.tmp", "rt");

	b = fopen("b.tmp", "rt");

	dest = fopen("dest.txt", "wt");

	int na = 1, nb = 1, ch_scrise = 0, read_next_a = 1;

	int read_next_b = 1, a_citit = 0, b_citit = 0, gata = 0;

	char ca, cb;

	while (ch_scrise < file_size)

	{

		do

		{

			if (read_next_a)

			{

				ca = fgetc(a);

				read_next_a = 0;

				a_citit++;

				if (a_citit > a_size) { gata = 1; na = nr + 1; }

			}

			if (read_next_b)

			{

				cb = fgetc(b);

				read_next_b = 0;

				b_citit++;

				if (b_citit > b_size) { gata = 1; nb = nr + 1; }

			}

			if (gata == 0)

				if (ca < cb)

				{

					fputc(ca, dest);

					ch_scrise++; read_next_a = 1; na++;

				}

				else

				{

					fputc(cb, dest);

					ch_scrise++; read_next_b = 1; nb++;

				}

		} while ((na <= nr) && (nb <= nr));

		if (nb <= nr)

		{

			fputc(cb, dest); ch_scrise++;

			for

				(int i = nb; ((i < nr) && (b_citit < b_size)); i++)

			{

				cb = fgetc(b); b_citit++;

				fputc(cb, dest); ch_scrise++;

			}

		}

		else

		{

			fputc(ca, dest); ch_scrise++;

			for

				(int i = na; ((i < nr) && (a_citit < a_size)); i++)

			{

				ca = fgetc(a); a_citit++;

				fputc(ca, dest); ch_scrise++;

			}

		}

		na = 1; read_next_a = 1;

		nb = 1; read_next_b = 1;

	}

	fclose(a);

	fclose(b);

	fclose(dest);

}

void sorteaza_destinatie()

{

	int n = 1;

	while (n <= file_size)

	{

		split_destinatie(n);

		interclaseaza(n);

		n *= 2;

	}

}

int main()

{

	transfera_sursa_in_destinatie();

	sorteaza_destinatie();

}
