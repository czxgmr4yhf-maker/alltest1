/*ABC*/
#include <stdio.h>
int main()
{
    //Input
    int s1[3];
    char s2[3];
    scanf("%d %d %d\n", &s1[0], &s1[1], &s1[2]);
    scanf("%c%c%c", &s2[0], &s2[1], &s2[2]);
    // printf("%c %c %c\n", s2[0], s2[1], s2[2]);

    //bubble sort
    for (int i = 0; i < 2; i++)
    {
        if (s1[0] > s1[1])
        {
            int m = s1[1];
            s1[1] = s1[0];
            s1[0] = m;
        }
        if (s1[1] > s1[2])
        {
            int m = s1[2];
            s1[2] = s1[1];
            s1[1] = m;
        }
    }
    int A = s1[0];
    int B = s1[1];
    int C = s1[2];

    //output
    for (int i = 0; i < 3; i++)
    {
        switch (s2[i])
        {
            case 'A':
                printf("%d ", A);
                break;

            case 'B':
                printf("%d ", B);
                break;

            case 'C':
                printf("%d ", C);
                break;
        }           
    }
     
    return 0;
}
