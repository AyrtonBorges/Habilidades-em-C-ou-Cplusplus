#include <iostream>

using namespace std;

int quant_sup = 0;
int quant_inf = 0;

int BuscaBinaria(int lista[], int chave, int Tam);

int main()
{
    int lista[] = {1,4,6,7,8,9,11,14,15,16,17,19,20,30,50,55,60,66,70,77,80,88,90,99,100,110,120,122,123,125,126,127,129,144,155,160,166,170,176,180,186,190,200,210,220,230,240,270,290,330};
    int tamanho = sizeof(lista)/sizeof(lista[0]);
    int chave = 15;
    cout << "Procurando por chave: " << chave << endl;
    int valor = BuscaBinaria(lista, chave, tamanho);
    cout << "Quantidade que repetiu o sup: " << quant_sup << endl;
    cout << "Quantidade que repetiu o inf: " << quant_inf << endl;
    cout << "O meio foi: " << valor << endl;
}

int BuscaBinaria(int lista[], int chave, int Tam)
{
    int inf = 0;
    int sup = Tam-1;
    int meio;
    while(inf <= sup)
    {
        meio = (inf + sup)/2;
        if(chave == lista[meio])
            return meio;
        if(chave < lista[meio])
        {
            sup = meio-1;
            quant_sup++;
        }
        else
        {
            inf = meio+1;
            quant_inf++;
        }
        cout << "Superior: " << sup << endl;
        cout << "Inferior: " << inf << endl;
    }
    return -1;
}