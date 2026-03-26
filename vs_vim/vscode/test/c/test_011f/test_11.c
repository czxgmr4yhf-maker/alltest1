/*三角形的分类*/
#include <stdio.h>

int main()
{
	int ll[3];
	
	scanf("%d %d %d", &ll[0], &ll[1], &ll[2]);
	
	//冒泡排序
	int i, j;
	for (i = 0; i<2; i++){
		for (j = 0; j<2; j++){
			int d;
			if(ll[j]>ll[j+1]){
				d = ll[j];
				ll[j] = ll[j+1];
				ll[j+1] = d;	//交换ll[j]和ll[j+1]的值			
			}
		}
	}
	
	//判断三角形形状
	int a, b ,c;
	a = ll[0];
	b = ll[1];
	c = ll[2];
	if(a + b <= c){
		printf("Not triangle\n");
	}else{
		if(a*a + b*b == c*c){
			printf("Right triangle\n");
		}
		if(a*a + b*b > c*c){
			printf("Acute triangle\n");
		}
		if(a*a + b*b < c*c){
			printf("Obtuse triangle\n");		
		}
		if(a == b){
			printf("Isosceles triangle\n");
		}
		if (a == b && a == c){
			printf("Equilateral triangle\n");
		}
	}
	
	return 0;
}