#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementação do algoritmo de eliminação de Gauss segundo consta na página
// 126 do livro Cálculo Numérico de Ruggiero e Lopes.
// Nesta versão usamos uma quantidade fixa de variáveis, N = 3. Portanto,
// a matriz de coeficientes terá N linhas x N colunas

int main()
{
    int n = 3; // quantidade de variáveis do sistema
    float A[n][n]; // matriz dos coeficientes;
    float b[n]; // vetor constante dos termos independentes
    float x[n]; // vetor das variáveis
    int i, j, k; // variáveis auxiliares para percorrer os coefs
    float m; // multiplicador usado na fase de eliminação
    float s; // auxiliar usada na fase de resolução

    //              Entrada de dados pelo usuário
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
    // apresento o resultado da fase de eliminação

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        printf("A matriz A e o vetor b resultaram transformados em: [%d][%d] %.2f \n",i+1,j+1,A[i][j]);
    }


    // ************ Exercício: incluir o código para mostrar A e b


    //              Fase de resolução
    x[n-1] = b[n-1] / A[n-1][n-1];
    for(k = n-2; k >= 0; k--){
        s = 0.0;
        for(j = k + 1; j < n; j++){
            s = s + A[k][j] * x[j];
        }
        x[k] = (b[k] - s) / A[k][k];
    }

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            for(k = j+1; k < n; k++)
            {
            printf("o vetor solução é %.2f \n",x[i]);
            printf("o vetor solução é %.2f \n",x[j]);
            printf("o vetor solução é %.2f \n",x[k]);
            }

        }
    }


    // apresento o resultado da fase de resolução


    // ************ Exercício: incluir o código para mostrar o conteúdo do vetor x
}
