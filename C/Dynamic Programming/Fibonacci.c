#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*  쳲��������� */
/*  ״̬����  fib[n]  =  fib[n-1] + fib[n-2] */
/*  �߽�����  fib[1] = 1  ,fib[2] = 1        */ 
/* �ݹ���ʽ   �Զ�����    */
int fib1(int n)
{
	if(n==1||n==2)
		return 1;
	else
	{
		return fib1(n-1)+fib1(n-2);	
	}	
	
} 

/* ��̬�滮��ʽ  �Ե׶��� */
int fib2(int n)
{
	int i =0;
	int temp;
	
	int *p = (int *)malloc(sizeof(int)*(n+1));
	p[0] =0 ;
	p[1] =1 ;
	for(i=2;i<=n;i++)
	{
		p[i]= p[i-1]+p[i-2]; //�ӽṹ״̬
		 
	}
	

	temp = p[n];
	free(p);
	return temp;
} 

int main()
{
	int ret ;
	
	ret = fib2(6);
	printf("Result is %d",ret);
	
	
	return 0;
}
