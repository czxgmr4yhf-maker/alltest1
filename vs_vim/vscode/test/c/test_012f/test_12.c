/*小玉家的电费*/
#include<stdio.h>

int main(){
	int cost;
	double ll[3]; 
	scanf("%d", &cost);
	
	//判断三个段的电费
	if (cost <= 150){
		ll[0] = cost * 0.4463;
		ll[1] = 0;
		ll[2] = 0;
	}else if (cost > 150 && cost <= 400){
		ll[0] = 150 * 0.4463;
		ll[1] = (cost - 150) * 0.4663;
		ll[2] = 0;
	}else if (cost > 400){
		ll[0] = 150 * 0.4463;
		ll[1] = (400 - 150) * 0.4663;
		ll[2] = (cost - 400) * 0.5663;
	}
	
	//总价格
	double sum = ll[0] + ll[1] + ll[2];
	printf("%.1f\n", sum);			//在scanf中才严格区分%lf和%f
	
	return 0;
}