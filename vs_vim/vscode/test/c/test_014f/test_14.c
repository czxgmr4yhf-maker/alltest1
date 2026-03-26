/*三角函数*/
#include <stdio.h>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	//defined
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int m;
	
	//permutation
	for (int i = 0; i<2; i++)
	{
		if(a > b)
		{
			m = b;
			b = a;
			a = m;
		}
		if(b > c)
		{
			m = c;
			c = b;
			b = m;
		}
	}
	
	//Euclidean algorithm
    int g = gcd(a, c);
	a /= g;
	c /= g;
	
	
	//input
	printf("%d/%d", a, c);
	
	return 0;
}