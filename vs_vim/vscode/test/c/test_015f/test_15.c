/*陶陶摘苹果*/
#include <stdio.h>
int main ()
{
    //input
    int ss[10];
    int a;
    scanf("%d %d %d %d %d %d %d %d %d %d", &ss[0], &ss[1], &ss[2], &ss[3], &ss[4], &ss[5], &ss[6], &ss[7], &ss[8], &ss[9]);
    scanf("%d", &a);

    //more apples
    a += 30;
    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        if ( a >= ss[i]){
            num ++;
        }
    }

    //output
    printf("%d", num);
    
    return 0;
}