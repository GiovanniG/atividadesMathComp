#include <stdio.h>
main ()
{
    float Ep=1;
    while ((1+Ep)>1)
    {
        Ep=Ep/2;
    }
    printf("%.50f",2*Ep);
}
