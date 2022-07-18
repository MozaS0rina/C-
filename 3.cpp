#include <iostream>
using namespace std;

int  n,m;
char x[20],k;
void afisare(int k)
{
    for (int j = 1; j <= k; j++)
        cout << x[j] << " ";
    cout << endl;
}

void recursiv(int k) {
    for (int i = k; i <= n; ++i)
    {
        x[k] = x[i];
        if (k == m)
            afisare(k);
        else
            recursiv(k + 1);
    }
}
int main() 
{
    cout << "Intrdouceti un numar n: \n";

    cin >> n;

    cout << "Introduceti n caractere: \n";

    int i;
    for (i = 0; i < n; i++)
    {
        cout << " x[" << i+1 << "]= ";
        cin >> x[i];
    }

    cout << "Cate caractere doriti intr-o grupa? (obligatoriu < n ) \n";
    cin >> m;

    recursiv(1);
    return 0;
}