#include<stdio.h>
int main() {

   int a;
   int day = 1;
    
   //input
   scanf("%d", &a);
    
   //calculate
   while (a != 1) {
      if (a % 2 == 0) {
         a = a / 2;
      }else {
         a = (a - 1) / 2;
      }
      day++;
   }
   
   //output
   printf("%d\n", day);
   return 0;
 }