/*月份天数*/

#include<stdio.h>

int isleap( int y );

int main(void)
{
	int y, m;
	
	scanf("%d %d", &y, &m);

	//正常年份,1 3 5 7 8 10 12,31天永不差
	int y_1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int Isleap = isleap(y);
	if (Isleap == 1){
		y_1[2 - 1] = 29; 
	}
	
	//输出结果
	printf("%d\n", y_1[m - 1]);
	
	return 0;
}
int isleap( int y )
{
	
	if ((y%4 == 0 && y%100 != 0) || y%400 == 0)
	{
		return 1;
	}else{
		return 0;
	}
}