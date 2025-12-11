#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int a,c;
	scanf("%ld\n%ld",&a,&c);
	long int b,sum;
	b=a;
	sum = 0 ; //我其实觉得唯一有可能有问题就是这个地方 因为sum初值有可能是别的随机值 oj里经常会出现的bug 
	if(c==1)
	{
		printf("%ld",a);
		exit(0);
	}
	if(a==0)
	{
		printf("%ld",a);
		exit(0);
	}
	if(c==0)
	{
		printf("0");
		exit(0);
	 } 
	for(;c>1;c--)
	{
		a=10*a+b;
		sum=sum+a;
	}
	printf("%ld",sum+b);
	return 0; 
}
