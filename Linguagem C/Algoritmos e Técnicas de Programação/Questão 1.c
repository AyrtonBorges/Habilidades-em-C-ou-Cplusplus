#include <stdio.h>
#include <stdbool.h>

bool testando = true;
float total1,total2,total3,qualquer = 1,quantidade1 = 0,quantidade2 = 0;    

int funcao();

int main()
{
    
    printf("Calculadora de consumo de energia: \n");
    funcao();
    printf("O total da residencial foi: %.02f\n",total1);
    printf("O total da comercial foi: %.02f\n",total2);
    printf("O total da industrial foi %.02f\n",total3);
    printf("A média do 1 foi: %.02f\n",(total1/quantidade1));
    printf("A média do 2 foi: %.02f\n",(total2/quantidade2));
}

int funcao()
{
    int codigo,tipo;
    float kwh;
    if(qualquer == 0)
        return 0;
    printf("Insira o número do consumidor: ");
    scanf("%d",&codigo);
    qualquer = codigo;
    printf("Insira a quantidade de KWh que consome por mês: ");
    scanf("%f",&kwh);
    bool teste;
    do
    {
        teste = false;
        printf("Insira se ele é 1- Residencial, 2- Comercial, 3- Industrial: ");
        scanf("%d",&tipo);
        if(!(tipo <= 3 && tipo >= 1))
        {
            printf("Entendi foi nada, nem existe esse tipo de consumidor!!\n");
            teste = true;
        }
    }while(teste);

    funcao();
    switch(tipo)
    {
        case 1:
            total1 += kwh;
            kwh *= 0.3;
            quantidade1++;
            break;
        case 2:
            total2 += kwh;
            kwh *= 0.5;
            quantidade2++;
            break;
        case 3:
            total3 += kwh;
            kwh *= 0.7;
            break;
            
    }
    printf("O código %d teve consumo de %.02f\n",codigo,kwh);
    return 0;
}
