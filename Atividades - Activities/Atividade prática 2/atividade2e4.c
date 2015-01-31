#include<stdio.h>
#include<math.h>
main ()
{
    float f,x=-4.0;
    while (x<=4.0)
    {
        f=(pow(x,3))-(pow(x,2))+8;
        printf("f(%.2f)= %.2f \n", x, f);
        x=x+0.1;
    }
}
