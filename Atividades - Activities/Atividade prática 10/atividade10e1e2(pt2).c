#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementação do algoritmo de eliminação de Gauss segundo consta na página
// 126 do livro Cálculo Numérico de Ruggiero e Lopes.
// Nesta versão, além de deixar ao usuário especificar a quantidade de variáveis,
// usamos a estratégia de pivotamento parcial para contornar o caso de termos
// um pivô nulo ou muito pequeno. Usamos o algoritmo descrito na página 127
// do livro de Cálculo Numérico de Ruggiero

/*
resultados:
x1=0.5 (correto=0,5)
x2=2,5 (correto=2,5)
*/


int main()
{
    int n; // quantidade de variáveis do sistema
    float **A; // matriz dos coeficientes;
    float *b; // vetor constante dos termos independentes
    float *x; // vetor das variáveis
    int i, j, k, p, q; // variáveis auxiliares para percorrer os coefs
    float m; // multiplicador usado na fase de eliminação
    float s; // auxiliar usada na fase de resolução
    float aux; // auxiliar usada na fase de pivotamento parcial

    //              Entrada de dados pelo usuário
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

    //              Fase de eliminação
    for(k = 0; k < (n-1); k++)
    {
        // escolhemos como pivó aquele coeficiente da coluna k com maior valor
        // absoluto
        aux = 0.0; // candidato de pivô
        p = 0;  // linha onde se encontra o coef com maior módulo
        for(q = k; q < n; q++)
        {
            if(fabs(A[q][k]) > aux)
            {
                aux = fabs(A[q][k]);
                p = q;
            }
        }
        // se o pivô encontrado é zero então aborto a execução do programa
        if(aux == 0.0)
        {
            printf("Detectado pivô nulo na fase de eliminação... Aborto o programa\n");
            // libero a memória reservada
            for(i = 0; i < n; i++)
            {
                free(A[i]);
            }
            free(A);
            free(b);
            free(x);
            exit(1); // forço a terminação do programa
        }
        // intercambio os coeficientes das equações k e p
        for(j=0; j < n; j++)
        {
            aux = A[k][j];
            A[k][j] = A[p][j];
            A[p][j] = aux;
        }
        aux = b[k];
        b[k] = b[p];
        b[p] = aux;

        // continuo o processo normal de eliminação
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
    // apresento o resultado da fase de eliminação
    printf("A matriz A e o vetor b resultaram transformados em:\n");


    // ************ Exercício: incluir o código para mostrar A e b
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


    //              Fase de resolução
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

    // apresento o resultado da fase de resolução
    printf("\n\nO vetor solução é \n");


    // ************ Exercício: incluir o código para mostrar x
    for(k=0;k<n;k++){
        printf("| %f ",x[k]);
    }


    // libero a memória reservada
    for(i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
}
