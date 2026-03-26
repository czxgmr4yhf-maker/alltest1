/*小鱼的航程*/
#include<stdio.h>

int main()
{
    int sum = 0;
    int x, n;
    int week[7] = { 1, 2, 3, 4, 5, 6, 7};

    scanf("%d %d", &x, &n);
    x--;
    
    //计算总路程
    for (; n>0; n--){
        if(week[x] != 6 && week[x] != 7){
            sum += 250;
        }
        // printf("x=%d\tsum =%d\n", x+1, sum);
        x++;
        if (x == 7){
            x = 0;
        }
            
    }

    //输出总公里数
    printf("%d\n", sum);
    return 0;
}