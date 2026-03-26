/*apples*/

#include <stdio.h>

int main()
{
	int num;
	
//输入
	scanf("%d", &num);
	
//输出
	if (num == 0 || num == 1) {
		printf("Today, I ate %d apple.\n", num);
	}else{
		printf("Today, I ate %d apples.\n", num);
	}
	
	return 0;
}