#include<stdio.h>

double area(double radius){
	double res = 3.14*radius*radius;
	return res;
}

double circum(double radius){
	double ret = 2*3.14*radius;
	return ret;
}
void main(){
	double radius;
	scanf("%lf",&radius);
	double ar = area(radius);
	double cr = circum(radius);
	printf("%lf\n",ar);
	printf("%lf",cr);
}
