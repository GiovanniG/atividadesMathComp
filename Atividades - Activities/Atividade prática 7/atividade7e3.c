#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Implementa��o do algoritmo de elimina��o de Gauss segundo consta na p�gina
// 126 do livro C�lculo Num�rico de Ruggiero e Lopes.
// Nesta vers�o usamos uma quantidade fixa de vari�veis, N = 3. Portanto,
// a matriz de coeficientes ter� N linhas x N colunas
// TIPO: Ax=b

/*
(a)
x=2
y=-1
z=4

(b) (#IND00)
x=
y=
z=

(c) (aborto no programa= infinitas solu��es)
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
x=10.33
y=13.00
z=10.33
*/



int main()
{
    int n; // quantidade de vari�veis do sistema (x,y,z)

    printf("Insira o n�mero de vari�veis: ");
    scanf("%d", &n);
    printf("\n");

    double A[n][n]; // matriz dos coeficientes;
    double b[n]; // vetor constante dos termos independentes
    double x[n]; // vetor das vari�veis
    int i, j, k; // vari�veis auxiliares para percorrer os coefs
    double m; // multiplicador usado na fase de elimina��o
    double s; // auxiliar usada na fase de resolu��o

    //              Entrada de dados pelo usu�rio
    // Entrada da matriz A
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
            printf("Digite o coeficiente A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &A[i][j]);}
    }
    // Entrada do vetor constante b
    for(i = 0; i < n; i++){
        printf("Digite o coeficiente b[%d] = ", i+1);
        scanf("%lf", &b[i]);    }

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
            printf(" %lf \t", A[i][j]);}
            printf("\n");}

    printf("\n\nVetor b:\n");

    for(i = 0; i < n; i++){
        printf(" %lf \n", b[i]);}

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
        printf(" %lf \n",x[i]);}
        printf("\n");
}
