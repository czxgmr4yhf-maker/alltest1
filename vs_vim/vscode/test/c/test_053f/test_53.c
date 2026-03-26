#include <stdio.h>
#define START 5000;

int main(){
    double income;
    int extraCost;
    scanf("%lf %d", &income, &extraCost);
    if (extraCost > 3000) extraCost = 3000;

    double tax = income - extraCost - START;

    double taxMoney;
    if (tax <= 0) {
        taxMoney = 0;
    } else if (tax <= 3000) {
        taxMoney = tax * 0.03;
     } else if (tax <= 12000) {
        taxMoney = tax * 0.1 - 210;
     } else if (tax <= 25000) {
        taxMoney = tax * 0.2 - 1410;
     }

     printf("应纳税所得额：%.2f元,应纳税额：%.2f元\n", tax, taxMoney);
}