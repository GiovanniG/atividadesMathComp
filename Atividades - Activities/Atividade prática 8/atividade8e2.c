#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementação do algoritmo de eliminação de Gauss segundo consta na página
// 126 do livro Cálculo Numérico de Ruggiero e Lopes.
// Nesta versão deixamos ao usuário especificar a quantidade de variáveis do sistema
// e reservamos a memória necessária para armazenar a matriz e os vetores

//Exercicio 5:
/*
x1=1
x2=2
x3=1
x4=0
*/
//Exercicio 6:
/*
(a) infinitas soluções (aborta o programa, pivo nulo)
(b) não admite solução (números muito grandes)
*/


int main()
{
    int n; // quantidade de variáveis do sistema
    float **A; // matriz dos coeficientes;
    float *b; // vetor constante dos termos independentes
    float *x; // vetor das variáveis
    int i, j, k; // variáveis auxiliares para percorrer os coefs
    float m; // multiplicador usado na fase de eliminação
    float s; // auxiliar usada na fase de resolução

    //              Entrada de dados pelo usuário
    // Entrada da quantidade de variáveis
    printf("Digite a quantidade de variáveis do sistema n = ");
    scanf("%d", &n);
    // reservo a quantidade de memória necessária
    A = malloc(n * sizeof(float*));
    for(i = 0; i < n; i++){
        A[i] = malloc(n * sizeof(float));
    }
    b = malloc(n * sizeof(float));
    x = malloc(n * sizeof(float));

    // Entrada da matriz A
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
            printf("Digite o coeficiente A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    // Entrada do vetor constante b
    for(i = 0; i < n; i++){
        printf("Digite o coeficiente b[%d] = ", i+1);
        scanf("%f", &b[i]);
    }

    //              Fase de eliminação
    for(k = 0; k < (n-1); k++){
        for(i = k + 1; i < n; i++){
            // o pivô é o coeficiente A[k][k] que precisa ser diferente de zero
            if(A[k][k] == 0.0){
                printf("Detectado pivô nulo na fase de eliminação... Aborto o programa\n");
                // libero a memória reservada
                for(i = 0; i < n; i++){
                    free(A[i]);
                }
                free(A);
                free(b);
                free(x);
                exit(1); // forço a terminação do programa
            }
            // calculo o multiplicador
            m = A[i][k] / A[k][k];
            // anulo o coef eliminado
            A[i][k] = 0.0;
            // calculo os novos valores para os demais coefs.
            for(j = k + 1; j < n; j++){
                A[i][j] = A[i][j] - m * A[k][j];
            }
            b[i] = b[i] - m * b[k];

        }
    }
    // apresento o resultado da fase de eliminação (mostrar A e b)
    printf("A matriz A e o vetor b resultaram transformados em:\n");

    // ************ Exercício: incluir o código para mostrar A e b
    printf("\nMatriz A:\n");
    for(i = 0; i < n; i++)    {
        for(j = 0; j < n; j++){
            printf("| %f ", A[i][j]);        }
            printf("\n");    }
    printf("\n\nVetor b:\n");
    for(i = 0; i < n; i++){
        printf("| %f ", b[i]);    }


    //              Fase de resolução
    x[n-1] = b[n-1] / A[n-1][n-1];
    for(k = n-2; k >= 0; k--){
        s = 0.0;
        for(j = k + 1; j < n; j++){
            s = s + A[k][j] * x[j];
        }
        x[k] = (b[k] - s) / A[k][k];
    }

    // apresento o resultado da fase de resolução (mostrar x)
    printf("\n\n O vetor solução é \n");

    // ************ Exercício: incluir o código para mostrar x
    for(k=0;k<n;k++){
        printf("| %f ",x[k]);
    }
    printf("\n");

    // libero a memória reservada
    for(i = 0; i < n; i++){
        free(A[i]);    }
    free(A);
    free(b);
    free(x);
}
