#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementa��o do algoritmo de elimina��o de Gauss segundo consta na p�gina
// 126 do livro C�lculo Num�rico de Ruggiero e Lopes.
// Nesta vers�o usamos uma quantidade fixa de vari�veis, N = 3. Portanto,
// a matriz de coeficientes ter� N linhas x N colunas
// TIPO: Ax=b

//Exercicio 5:
/*
x1=1
x2=2
x3=1
x4=0
*/
//Exercicio 6:
/*
(a) infinitas solu��es (aborta o programa)
(b) n�o admite solu��o (n�meros muito grandes)
*/


int main()
{
    int n = 4; // quantidade de vari�veis do sistema
    float A[n][n]; // matriz dos coeficientes;
    float b[n]; // vetor constante dos termos independentes
    float x[n]; // vetor das vari�veis
    int i, j, k; // vari�veis auxiliares para percorrer os coefs
    float m; // multiplicador usado na fase de elimina��o
    float s; // auxiliar usada na fase de resolu��o

    //              Entrada de dados pelo usu�rio
    // Entrada da matriz A
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
            printf("Digite o coeficiente A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);}
    }
    // Entrada do vetor constante b
    for(i = 0; i < n; i++){
        printf("Digite o coeficiente b[%d] = ", i+1);
        scanf("%f", &b[i]);    }

    // Fase de elimina��o
    for(k = 0; k < (n-1); k++){
        for(i = k + 1; i < n; i++){
            // o piv� � o coeficiente A[k][k] que precisa ser diferente de zero
            if(A[k][k] == 0.0){
                printf("Detectado piv� nulo na fase de elimina��o... Aborto o programa\n");
                exit(1); // for�o a termina��o do programa
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

// apresento o resultado da fase de elimina��o (mostrar a matriz A e b)
// ************ Exerc�cio: incluir o c�digo para mostrar A e b

    printf("A matriz A e o vetor b resultaram transformados em:\n");
    printf("\nMatriz A:\n");

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf(" %.3 \t", A[i][j]);}
            printf("\n");}

    printf("\n\nVetor b:\n");

    for(i = 0; i < n; i++){
        printf(" %.3f \n", b[i]);}

    // Fase de resolu��o
    x[n-1] = b[n-1] / A[n-1][n-1];
    for(k = n-2; k >= 0; k--){
        s = 0.0;
        for(j = k + 1; j < n; j++){
            s = s + A[k][j] * x[j];}
        x[k] = (b[k] - s) / A[k][k];}

// apresento o resultado da fase de resolu��o(vetor x)
// ************ Exerc�cio: incluir o c�digo para mostrar o conte�do do vetor x

    printf("\n\nO vetor solu��o �: \n");
    for(i=0;i<n;i++){
        printf(" %.3f \n",x[i]);}
        printf("\n");
}
