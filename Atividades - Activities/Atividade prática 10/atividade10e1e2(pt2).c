#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementa��o do algoritmo de elimina��o de Gauss segundo consta na p�gina
// 126 do livro C�lculo Num�rico de Ruggiero e Lopes.
// Nesta vers�o, al�m de deixar ao usu�rio especificar a quantidade de vari�veis,
// usamos a estrat�gia de pivotamento parcial para contornar o caso de termos
// um piv� nulo ou muito pequeno. Usamos o algoritmo descrito na p�gina 127
// do livro de C�lculo Num�rico de Ruggiero

/*
resultados:
x1=0.5 (correto=0,5)
x2=2,5 (correto=2,5)
*/


int main()
{
    int n; // quantidade de vari�veis do sistema
    float **A; // matriz dos coeficientes;
    float *b; // vetor constante dos termos independentes
    float *x; // vetor das vari�veis
    int i, j, k, p, q; // vari�veis auxiliares para percorrer os coefs
    float m; // multiplicador usado na fase de elimina��o
    float s; // auxiliar usada na fase de resolu��o
    float aux; // auxiliar usada na fase de pivotamento parcial

    //              Entrada de dados pelo usu�rio
    // Entrada da quantidade de vari�veis
    printf("Digite a quantidade de vari�veis do sistema n = ");
    scanf("%d", &n);
    // reservo a quantidade de mem�ria necess�ria
    A = malloc(n * sizeof(float*));
    for(i = 0; i < n; i++)
    {
        A[i] = malloc(n * sizeof(float));
    }
    b = malloc(n * sizeof(float));
    x = malloc(n * sizeof(float));

    // Entrada da matriz A
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Digite o coeficiente A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    // Entrada do vetor constante b
    for(i = 0; i < n; i++)
    {
        printf("Digite o coeficiente b[%d] = ", i+1);
        scanf("%f", &b[i]);
    }

    //              Fase de elimina��o
    for(k = 0; k < (n-1); k++)
    {
        // escolhemos como piv� aquele coeficiente da coluna k com maior valor
        // absoluto
        aux = 0.0; // candidato de piv�
        p = 0;  // linha onde se encontra o coef com maior m�dulo
        for(q = k; q < n; q++)
        {
            if(fabs(A[q][k]) > aux)
            {
                aux = fabs(A[q][k]);
                p = q;
            }
        }
        // se o piv� encontrado � zero ent�o aborto a execu��o do programa
        if(aux == 0.0)
        {
            printf("Detectado piv� nulo na fase de elimina��o... Aborto o programa\n");
            // libero a mem�ria reservada
            for(i = 0; i < n; i++)
            {
                free(A[i]);
            }
            free(A);
            free(b);
            free(x);
            exit(1); // for�o a termina��o do programa
        }
        // intercambio os coeficientes das equa��es k e p
        for(j=0; j < n; j++)
        {
            aux = A[k][j];
            A[k][j] = A[p][j];
            A[p][j] = aux;
        }
        aux = b[k];
        b[k] = b[p];
        b[p] = aux;

        // continuo o processo normal de elimina��o
        for(i = k + 1; i < n; i++)
        {
            // calculo o multiplicador
            m = A[i][k] / A[k][k];
            // anulo o coef eliminado
            A[i][k] = 0.0;
            // calculo os novos valores para os demais coefs.
            for(j = k + 1; j < n; j++)
            {
                A[i][j] = A[i][j] - m * A[k][j];
            }
            b[i] = b[i] - m * b[k];
        }
    }
    // apresento o resultado da fase de elimina��o
    printf("A matriz A e o vetor b resultaram transformados em:\n");


    // ************ Exerc�cio: incluir o c�digo para mostrar A e b
    printf("\nMatriz A:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
            printf("| %f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\nVetor b:\n");
    for(i = 0; i < n; i++){
        printf("| %f ", b[i]);
    }


    //              Fase de resolu��o
    x[n-1] = b[n-1] / A[n-1][n-1];
    for(k = n-2; k >= 0; k--)
    {
        s = 0.0;
        for(j = k + 1; j < n; j++)
        {
            s = s + A[k][j] * x[j];
        }
        x[k] = (b[k] - s) / A[k][k];
    }

    // apresento o resultado da fase de resolu��o
    printf("\n\nO vetor solu��o � \n");


    // ************ Exerc�cio: incluir o c�digo para mostrar x
    for(k=0;k<n;k++){
        printf("| %f ",x[k]);
    }


    // libero a mem�ria reservada
    for(i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
}
