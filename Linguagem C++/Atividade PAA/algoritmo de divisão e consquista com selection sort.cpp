#include <iostream>

using namespace std;

int BuscaBinaria(int lista[], int chave, int Tam);
void selectionsort(int *lista, int tam);

int main()
{
    int lista[] = {1,4,6,7,8,9,11,14,17,19};
    int tamanho = 10;
    selectionsort(lista, tamanho);
    int chave = 17;
    cout << "Procurando por chave: " << chave << endl;
    int valor = BuscaBinaria(lista, chave, tamanho);
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
            sup = meio-1;
        else
            inf = meio+1;
        cout << "Superior: " << sup << endl;
        cout << "Inferior: " << inf << endl;
    }
    return -1;
}

void selectionsort(int *lista, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        int menor = i;
        for(int y = i+1; y < tam; y++)
        {
            if(lista[y] < lista[menor])
            {
                menor = y;
            }
        }
        int temp = lista[i];
        lista[i] = lista[menor];
        lista[menor] = temp;
    }
}