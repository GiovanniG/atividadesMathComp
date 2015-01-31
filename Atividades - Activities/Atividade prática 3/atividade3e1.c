#include <stdio.h>
#include <math.h>

// Implementação do algoritmo de bisseção segundo consta na página
// 43 do livro Cálculo Numérico de Ruggiero e Lopes

// Função cuja raiz deve ser determinada
float f(float x)
{
    return (pow(x,3))-(9*x)+3;
}

int main()
{
    // declaração de variáveis
    float epsilon; // precisão desejada
    float esquerdo; // extremo esquerdo do intervalo
    float direito; // extremo direito do intervalo
    float medio; // ponto médio do intervalo
    float largura = direito - esquerdo; // largura do intervalo
    int maximoIteracoes = 100; // limite de segurança na quantidade de iterações
    int iteracoes = 0;

    // peço os dados ao usuário
    printf("Digite o extremo esquerdo do intervalo:\n");
    scanf("%f",&esquerdo);
    printf("Digite o extremo direito do intervalo:\n");
    scanf("%f",&direito);
    printf("Digite a precisão requerida:\n");
    scanf("%f",&epsilon);

    // atualizo o valor da largura do intervalo
    largura = direito - esquerdo;

    // calculo a abcisa do ponto médio
    medio = (esquerdo + direito) / 2.0;

    // itero até o intervalo ter uma largura menor que a precisao desejada
    while(largura > epsilon)
    {
        // calculo a abcisa do ponto médio
        medio = (esquerdo + direito) / 2.0;

        // calculo o valor da função no ponto médio
        float fMedio = f(medio);

        // confiro se o ponto medio é a raiz buscada
        if(fMedio == 0.0){
            // termino o while pois já encontrei o valor buscado
            break;
        }

        // se o ponto médio não é a raiz buscada, então vou
        // determinar em qual das duas metades do intervalo
        // encontra-se a raiz
        if(f(esquerdo) * f(medio) < 0)
        {
            // a raiz encontra-se na metade esquerda do intervalo
            direito = medio;
        }
        else
        {
            // a raiz encontra-se na metade direita do intervalo
            esquerdo = medio;
        }

        // atualizo o valor da largura do intervalo
        largura = direito - esquerdo;

        // atualizo o contador de interações
        iteracoes = iteracoes + 1;

        // confiro se cheguei ao limite de segurança de iterações
        if( iteracoes >= maximoIteracoes )
        {
            // cheguei ao limite: aviso o usuário e termino o while
            printf("Limite de iterações (=%d) atingido!!!\n\n", maximoIteracoes);
            break;
        }

    }

    // calculo o ponto médio do intervalo final para usar como valor
    // estimado da raiz
    medio = (esquerdo + direito) / 2.0;

    // informo ao usuário o valor estimado para a raiz
    printf("Após %d iterações foi obtido x = %f e f(x) = %f\n", iteracoes, medio, f(medio));

    // termino a execução do programa
    return 0;
}
