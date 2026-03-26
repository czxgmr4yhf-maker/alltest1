/*洛谷团队系统*/

#include<stdio.h>

int main()
{
	int n;
	int luo;
	int loc;
	const int beg = 11;
	
	scanf("%d", &n);

//get the all cost
	luo = beg + n*3;
	loc = n*5;

//contrast
	if(loc < luo){
		printf("Local\n");
	}else{
		printf("Luogu\n");
	}
	
	return 0;
}