#include <stdio.h>
#include <string.h>
#include <stdlib.h>
{
int func(int n)
{
if (n == 1) {
return 1;
} else {
return n * func(n – 1);
}
}
int n;
int a;
scanf("%d",&n);
a=func(n);
printf("N!=%d",a);
}
