#include <stdio.h>
#include <math.h>

void redpill();
void delay(int tempo);
int main()
{
    int escolha;
    printf("-----------------------\n");
    printf("-Bem-Vindo Consagrado!-\n");
    printf("-----------------------\n");
    inicio:
    printf("Você deseja usar qual cálculo?\n");
    printf("1- Para a e b são constantes\nou \n2- Para x e y são grandesas adimensionais\n");
    printf("Insira aqui: ");
    scanf("%d",&escolha);
    switch(escolha)
    {
        case 1:
            break;
        case 2:
            redpill();
            break;
        default:
            printf("\n\nOchi, nem tem nas escolhas, tenta novamente!\n\n");
            delay(1);
            goto inicio;
    }
}

// x e y são grandesas 
void redpill()
{
    int escolha;
    float x,y,inx,iny,incerteza,media,s1,s2,raiz;
    volta:
    printf("Por favor insira x, y e sua incerteza depois!\n");
    printf("x e y, separados por vírgula (exemplo: \'x\',\'y\'): ");
    scanf("%f,%f",&x,&y);
    printf("Insira a incerteza agora de x e y separados por vírgula: ");
    scanf("%f,%f",&inx,&iny);
    printf("Agora me diga, meu consagrado, qual cálculo você quer?\n");
    printf("1- f(x,y) = x + y | u(f) = raiz^2[u(x)^2+u(y)^2]\n");
    printf("2- f(x,y) = x * y | u(f) = raiz^2[(y*u(x))^2+(x*u(y))^2]\n");
    printf("3- f(x,y) = x / y | u(f) = (1/y^2)*raiz^2[(y*u(x))^2+(x*u(y))^2]\n");
    printf("Escolha: ");
    scanf("%d",&escolha);
    switch(escolha)
    {
        case 1:
            incerteza = sqrt(((inx)*(inx))+((iny)*(iny)));
            media = x+y;
            break;
        case 2:   
            s1 = y*inx;
            s2 = x*iny; 
            incerteza = sqrt(((s1*s1)+(s2*s2)));
            media = x*y;
            break;
        case 3: 
            s1 = y*inx;
            s2 = x*iny;
            raiz = sqrt(((s1*s1)+(s2*s2)));
            incerteza = raiz/(y*y);
            media = x*y;
            break;
        default:
            printf("\nOchi, nunca nem vi essa opção, tenta novamente!\n");
            delay(1);
            goto volta;
    }
    printf("O resultado: (%.07f+-%.07f)",media,incerteza);
}

// Causa um tempo de espera
void delay(int tempo)
{
    for(int i = 0; i < 32765*tempo; i++)
        for(int y = 0; y < 32765*tempo; y++)
            {}
}
