#include <iostream>

using namespace std;

void selectionsort(int *lista, int tam);

int main()
{
    cout << "Fazendo teste do selection sort:" << endl;
    int tamanho = 7;
    int lista [] = {10,4,7,3,66,84,3};
    cout << "Desordenado: " << endl;
    for(int i = 0; i < tamanho; i++)
        cout << lista[i] << ',';
    cout << endl;
    selectionsort(lista,tamanho);
    cout << "Ordernado: " << endl;
    for(int i = 0; i < tamanho; i++)
        cout << lista[i] << ',';
    cout << endl;
}

// Função SelectionSort
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