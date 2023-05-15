#include <iostream>

using namespace std;

void troco(int *moedas, int *temp, int tro);

int main()
{
    cout << "Algoritmos Gulosos, teste no algoritmo do troco: " << endl;
    int moedas[] = {1,2,5,10,20};
    int temp[] = {0,0,0,0,0};
    int tro = 38;
    troco(moedas, temp, tro);
    cout << "Quais notas eu preciso devolver: " << endl;
    for(int i = 4; i >= 0; i--)
        cout << moedas[i] << ":" << temp[i] << endl;

}

void troco(int *moedas, int *temp, int tro)
{
    int quant_m = 0;
    for(int i = 4; i >= 0; i--)
    {
        while(true)
        {
            if(moedas[i] <= tro)
            {
                tro -= moedas[i];
                temp[i]++;
            }else
                break;
        }
        
    }
}