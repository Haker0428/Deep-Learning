/*  动态规划---------硬币找零问题   */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min(a,b) (a>=b)?b:a
/*  状态方程 : find[n] = min{find(n-value)+1}  */
/* 边界条件:  find[0] = 0 find[1] =1 find[2]=2  find[3] = 1 find[4]=4  find[5]=1*/

int v[3] ={1,3,5}; 

/*   递归方式  */
int find1(int n)
{
	int i;
	int ret=999999;
	
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 1;
	if(n==4)
		return 2;
	if(n==5)
		return 1;
	
	else
	{
		 for(i=0;i<3;i++)
		 {
		 	ret= min(find1(n-v[i])+1,ret); 
		 }
	}	
	return ret;
	
}

/*自底向上  动态规划方法*/
int find2(int n )
{
	int i,j;
	int ret=999999;
	
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 1;
	if(n==4)
		return 2;
	if(n==5)
		return 1;
		
	int *p = (int *)malloc(sizeof(int)*(n+1));
	
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 1;
	p[4] = 2;
	p[5] = 1;
	
	for(i=6;i<=n;i++)
	{
		ret = 99999;
		for(j=0;j<3;j++)
			ret= min(p[i-v[j]]+1,ret); 
			
		p[i] = ret;
	}	
	
	ret = p[n];
	free(p);
	return ret;
} 
int main()
{
	
	int ret ;
	int i ;
	printf("---------递归法---------------\n");
	for(i=0;i<12;i++)
	{
	
		ret = find1(i);
		printf("凑齐%d 元,最少需要%d个硬币\n",i,ret);
	}	
		
	printf("\n---------动态规划法---------------\n");
	for(i=0;i<12;i++)
	{
	
		ret = find2(i);
		printf("凑齐%d 元,最少需要%d个硬币\n",i,ret);
	}	
	return 0;
}

