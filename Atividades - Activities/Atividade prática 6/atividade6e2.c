#include <stdio.h>
#include <math.h>
float fatorial (float f)
{
    if (f<=1.0)
        return 1.0;
    else
        return (f*fatorial(f-1.0));
}
main ()
{
    float N,x,i,aux,SN,funcao,diferenca;
    printf("Digite um inteiro positivo: \n");
    scanf("%f",&N);
    printf("Digite um valor de x: \n");
    scanf("%f",&x);
    SN=0.0;
    for (i=0.0;i<=N;i++)
    {
        aux=((pow(x,2.0*i+1.0))/fatorial(2.0*i+1.0))*(pow(-1.0,i));
        SN=SN+aux;
    funcao=sin(x);
    }
    diferenca=fabs(funcao-SN);
    printf("O valor de SN �: %.10f \n",SN);
    printf("O valor da fun��o f(x)=sen(x) �: %.10f \n",funcao);
    printf("A diferen�a de SN e da fun��o f(x) �: %.10f \n",diferenca);
}
/*Nome	Descri��o
acos	arco-coseno
asin	arco-seno
atan	arco-tangente
atan2	arco-tangente (c�rculo cheio)
ceil	Arredonda para cima
cos	co-seno
cosh	co-seno hiperb�lico
exp	exponencial
fabs	valor absoluto (m�dulo de)
floor	Arredonda para baixo
fmod	resto de uma divis�o
frexp	frac��o norm./parte exp
ldexp	inverso de frexp
log	logaritmo natural
log10	logaritmo base 10
modf(x,p)	retorna a parte fraccion�ria de x e guarda a parte inteira para onde o apontador p aponta
pow(x,y)	retorna o resultado de x elevado a y
sin	seno
sinh	seno hiperb�lico
sqrt	raiz quadrada
tan	tangente
tanh	tangente hiper�lica */

