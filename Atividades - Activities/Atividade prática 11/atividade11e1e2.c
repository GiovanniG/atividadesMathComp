#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementação do algoritmo de Gauss-Jacobi segundo consta na página
// 157 do livro Cálculo Numérico de Ruggiero e Lopes.

/*
(a)
x=
y=
z=

(b)
x=
y=
z=

(c)
x1=
x2=
x3=
x4=

(d)
x1=
x2=
x3=
x4=
x5=

(e)
x=
y=
z=
*/

int main()
{
    int n; // quantidade de variáveis do sistema
    float **A; // matriz dos coeficientes;
    float *b; // vetor constante dos termos independentes
    float *x; // vetor das variáveis
    float *d; // vetor de convergência
    int i, j; // variáveis auxiliares para percorrer os coefs
    int ItMax = 100; //número máximo de iterações
    int It = 0; //contador de iterações
    float epsilon; //precisao desejada
    float auxX, auxmaxd, somaL, maxd; //variaveis auxiliares

    // Entrada de dados pelo usuário

    printf("Digite a precisao requerida: ");
    scanf("%f",&epsilon);

    // Entrada da quantidade de variáveis
    printf("Digite a quantidade de variáveis do sistema n = ");
    scanf("%d", &n);
    // reservo a quantidade de memória necessária
    A = malloc(n * sizeof(float*));
    for(i = 0; i < n; i++)
    {
        A[i] = malloc(n * sizeof(float));
    }
    b = malloc(n * sizeof(float));
    x = malloc(n * sizeof(float));
    d = malloc(n * sizeof(float));

    // Entrada da matriz A
    printf("\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Digite o coeficiente A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    printf("\n");

    // Entrada do vetor constante b
    for(i = 0; i < n; i++)
    {
        printf("Digite o coeficiente b[%d] = ", i+1);
        scanf("%f", &b[i]);
    }
    printf("\n");

    // Entrada do vetor x - aproximcao inicial
    for(i = 0; i < n; i++)
    {
        printf("Digite a primeira aproximacao de x[%d] = ", i+1);
        scanf("%f", &x[i]);
    }
    printf("\n");


    // Fase de resolução
    do
    {
//*****************************************************************
//*** Exercício - implemente a fase de resolução iterativa aqui ***
//*****************************************************************


    // Obtencao da proxima aproximacao
    for(i=0; i<=n-1; i++)
    {
        somaL = 0;
        for(j=0; j<=n-1; j++)
        {
            if(i!=j)
            {
                somaL=somaL+A[i][j]*x[j];
            }
        }
        auxX=x[i];// Salvando cópia da aproximação
        x[i]=(1.0/A[i][i])*(b[i]-somaL);// Calculando nova aproximação

        // Calcula precisão da aproximação
        d[i]=fabs(x[i]-auxX);
    }


        // Encontrando o maior erro de aproximacao
        auxmaxd = 0;
        for(i = 0; i < n; i++)
        {
            if (d[i]>auxmaxd)
            {
                maxd = d[i];
                auxmaxd = maxd;
            }
        }

        It = It + 1;

    }while ((maxd > epsilon)&&(It < ItMax));

    // apresento o resultado da fase de resolução
    printf("O vetor solucao é \n");

    // código para mostrar x
    for(i = 0; i < n; i++)
    {
        printf("| %f ",x[i]);
    }
    printf("\n");


    // libero a memória reservada
    for(i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
}
