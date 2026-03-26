/*purchase pens*/
#include <stdio.h>

int cost(int total_num, int x, int y);
int main()
{
	//the total number that you want
	int total_num;
	scanf("%d", &total_num);
	
	//the number and price of pens
	int a1, a2;
	scanf("%d %d", &a1, &a2);
	int b1, b2;
	scanf("%d %d", &b1, &b2);
	int c1, c2;
	scanf("%d %d", &c1, &c2);
	
	//get the least cost
	int cost1 = cost(total_num, a1, a2);
	int cost2 = cost(total_num, b1, b2);
	int cost3 = cost(total_num, c1, c2);
	
	int least = cost1;
	if(least>cost2){
		least = cost2;
	}
	if(least>cost3){
		least = cost3;
	}
	
	//input
	printf("%d\n", least);
	
	return 0;
}
int cost(int total_num, int x, int y)
{
	if(total_num%x == 0){
		return (total_num/x) * y;
	}else{
		return (total_num/x + 1) * y;
	}
}