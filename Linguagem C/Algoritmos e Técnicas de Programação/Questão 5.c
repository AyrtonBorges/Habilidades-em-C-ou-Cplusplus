#include <stdio.h>

int main()
{
    float rendap=0,rendaf=0,totala=0,totald=0,porcentgo=0;
    int quantgo=0,quantr=0, quanttotalalu=0;
    do
    {
        printf("Insira a renda pessoal: ");
        scanf("%f",&rendap);
        if(rendap == 0)
            break;
        printf("Insira a renda familiar: ");
        scanf("%f",&rendaf);
        printf("Insira o total gasto com alimentação: ");
        scanf("%f",&totala);
        printf("Insira o total gasto com outras despesas: ");
        scanf("%f",&totald);
        quanttotalalu++;
        if(totald > 200)
            quantgo++;
        if(rendap > rendaf)
            quantr++;
        porcentgo += (totala+totald)/(rendap+rendaf);

    }while(rendap != 0);
    printf("Porcentagem dos alunos que gasta acima de R$200,00 com outras despesas: %.02f%%\n",(((float)quantgo/(float)quanttotalalu)*100.0));
    printf("Quantidade de alunos com renda pessoal maior que renda familiar: %d\n",quantr);
    printf("Porcentagem gasta com alimentação e outras despesas em relação às rendas pessoal e familiar: %.02f%%\n",((porcentgo/quanttotalalu)*100));

}
