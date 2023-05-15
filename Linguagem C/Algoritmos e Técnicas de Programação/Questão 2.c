#include <stdio.h>

int main()
{
    int num;
    printf("Insira um número qualquer aí: ");
    scanf("%d",&num);
    printf("O seu antecessor é %d e o seu sucessor é %d\n",(num-1),(num+1));
}
