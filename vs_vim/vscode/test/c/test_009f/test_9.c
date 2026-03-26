/*不高兴的津津*/
#include<stdio.h>

int main()
{
	//a plan of a week
	int a1, a2;
	scanf("%d %d", &a1, &a2);
	int sum1 = a1 + a2;
	
	int b1, b2;
	scanf("%d %d", &b1, &b2);
	int sum2 = b1 + b2;	
	
	int c1, c2;
	scanf("%d %d", &c1, &c2);
	int sum3 = c1 + c2;	
	
	int d1, d2;
	scanf("%d %d", &d1, &d2);
	int sum4 = d1 + d2;	
	
	int e1, e2;
	scanf("%d %d", &e1, &e2);
	int sum5 = e1 + e2;	
	
	int f1, f2;
	scanf("%d %d", &f1, &f2);
	int sum6 = f1 + f2;	
	
	int g1, g2;
	scanf("%d %d", &g1, &g2);
	int sum7 = g1 + g2;
	
	//search the biggest number
	int ser = 0;
	int num = 0;
	
	if ( sum1>8 && sum1>num ){
		ser = 1;
		num = sum1;
	}
	
	if ( sum2>8 && sum2>num ){
		ser = 2;
		num = sum2;
	}
	
	if ( sum3>8 && sum3>num){
		ser = 3;
		num = sum3;
	}
	
	if ( sum4>8 && sum4>num){
		ser = 4;
		num = sum4;
	}
	
	if ( sum5>8 && sum5>num){
		ser = 5;
		num = sum5;
	}
	
	if ( sum6>8 && sum6>num){
		ser = 6;
		num = sum6;
	}
	
	if ( sum7>8 && sum7>num){
		ser = 7;
		num = sum7;
	}
	
	//input the result
	printf("%d\n", ser);
	
	return 0;
}