/*闰年判断法*/

#include<stdio.h>

int main()
{
	int year;
	int isleap = 0;
	
//输入整数	
	scanf("%d", &year);
	
//年份的判断
	if (year%4 == 0 && year%100 != 0){
		isleap = 1;
	}
	if (year%400 == 0){
		isleap = 1;
	}
	
//输出
	printf("%d\n", isleap);
	
	return 0;
}