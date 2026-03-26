#include <stdio.h>

int main(){

   int num[5] = {0};

   for (int i = 0; i < 5; i++) {

       scanf("%d", &num[i]);        //实现数组的输入

   }



   int sum = 0;

   for(int i = 0; i < 5; i++) {

       sum += num[i];              //数组的所有元素求和

   }



   printf("%d", sum);

}







#include <stdio.h>

void reverse(int num[]);             //定义一个翻转函数



int main(){

   int num[6] = {0};

   for (int i = 0; i < 6; i++){        //获取原数组

       scanf("%d", &num[i]);

   }



   reverse(num);       //翻转

   for (int i = 0; i < 6; i++) {

       printf("%d ", num[i]);           //输出

   }

   printf("\n");

}

void reverse(int num[]) {

   for (int i = 0; i < 3; i++) {

       int tmp = num[i];

       num[i] = num[5 - i];

       num[5 - i] = tmp;

   }

}

#include <stdio.h>

int main(){

   int a, b;

   scanf("%d %d", &a, &b);



   int* p1 = &a;              

   int* p2 = &b;                           //赋值

   printf("a = %p, b = %p\n", &a, &b);

   printf("p1 = %p, p2 = %p\n", p1, p2);

   printf("&p1 = %p, &p2 = %p\n", &p1, &p2);       //输出



   int tmp = *p1;

   *p1 = *p2;

   *p2 = tmp;                          //交换

   printf("\n\n");

   printf("a = %p, b = %p\n", &a, &b);

   printf("p1 = %p, p2 = %p\n", p1, p2);

   printf("&p1 = %p, &p2 = %p\n", &p1, &p2);       //输出

}


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




