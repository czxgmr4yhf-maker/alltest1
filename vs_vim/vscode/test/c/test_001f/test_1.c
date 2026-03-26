/*输出字符菱形*/

#include<stdio.h>

int main()
{
	const int row = 5;
	
	//前四行
	for (int i = 0; i < row - 2; i++)
	{
			for (int j = 2 - i; j > 0; j--)
			{
				printf(" ");
			}
			for (int k = 2*i + 1; k > 0; k--)
			{
				printf("*");
			}
			printf("\n");
	}
	
	//后四行
	for (int i = 3; i < row; i++)
	{
		for (int j = i - 2; j > 0; j--)
		{
			printf(" ");
		}
		for (int k = 9 - 2*i; k > 0; k--)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}