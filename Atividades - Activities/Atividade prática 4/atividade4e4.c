#include <stdio.h>
#include <math.h>

// Implementação do algoritmo d a secante segundo consta na página
// 76 do livro Cálculo Numérico de Ruggiero e Lopes

// Função cuja raiz deve ser determinada
float f(float x)
{
    return (pow(x,3))-(9*x)+3;
}

int main()
{
    // declaração de variáveis
    float x0; // aproximação inicial fornecida pelo usuário
    float x1; // aproximação inicial fornecida pelo usuário
    float epsilon; // precisão desejada fornecida pelo usuário
    float largura=fabs(x1 - x0); // distância entre aproximações
    float x2; // aproximação calculada a partir das aproximações iniciais
    float fx2; // valor da função na aproximação calculada
    int maximoIteracoes; // limite de segurança na quantidade de iterações
    int iteracoes;

    // peço os dados ao usuário para inicializar o conteúdo das variáveis
    printf("Digite a primeira aproximação inicial:\n");
    scanf("%f",&x0);
    printf("Digite a segunda aproximação inicial:\n");
    scanf("%f",&x1);
    printf("Digite a precisão requerida:\n");
    scanf("%f",&epsilon);

    // ************* inicializo o conteúdo das variáveis *************
    // inicializo o valor da largura do intervalo
    largura = fabs(x1 - x0);

    // inicializo a abcisa da aproximação calculada
    x2 = x1 - f(x1) / (f(x1)-f(x0)) * (x1 - x0);

    // inicializo o valor da função na aproximação calculada
    fx2 = f(x2);

    // invento um valor razoável para o máximo de iterações que vou tolerar
    maximoIteracoes = 100;

    // inicializo o contador de iterações
    iteracoes = 0;

    // itero até o intervalo ter uma largura menor que a precisao desejada
    while((largura > epsilon) && (fabs(fx2) > epsilon))
    {
        // atualizo a abcisa da aproximação calculada
        x2 = x1 - f(x1) / (f(x1)-f(x0)) * (x1 - x0);

        // atualizo o valor da função na aproximação calculada
        fx2 = f(x2);

        // confiro se x2 é a raiz buscada
        if(fx2 == 0.0){
            // termino o while pois já encontrei o valor buscado
            break;
        }

        // se a aproximação calculada não é a raiz buscada, então vou
        // usar x1 e x2 como as aproximações a serem usadas na próxima iteração
        x0 = x1;
        x1 = x2;

        // atualizo o valor da largura do intervalo
        largura = fabs(x1 - x0);

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

    // informo ao usuário o valor estimado para a raiz usando x2 como melhor aproximação
    printf("Após %d iterações foi obtido x = %.10f e f(x) = %.10f\n", iteracoes, x2, f(x2));

    // termino a execução do programa
    return 0;
}
