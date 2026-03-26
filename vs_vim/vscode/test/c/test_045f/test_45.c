#include <stdio.h>

void modify_arry(int arry[]);

int main(){

   int num[5];

   for (int i = 0; i < 5; i++) {

       scanf("%d", &num[i]);

   }



   modify_arry(num);               //对数组进行变化

   for (int i = 0; i < 5; i++){       //输出

       printf("%d ", num[i]);

   }

   printf("\n");

}

void modify_arry(int arry[]) {

   for (int i = 0; i < 5; i++){

       arry[i] += 5;

   }

}




