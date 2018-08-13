#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>=b)?a:b

/*  House robber 
Exp: 
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/

/*状态方程：rob(n) = Max{rob(n-2)+vi,rob(n-1)}  */
/*边界条件:rob(1) = v1   rob(2) = v2  */

/* 递归方法 */ 

int rob1(int* nums, int index) {
     
	 if(index==0)
     	return nums[0];
     if(index==1) 
     	return nums[1];
    	
     return max(rob1(nums,index-2)+nums[index],rob1(nums,index-1));
} 

/* 动态规划方法*/
int rob2(int* nums, int numsSize) 
{
	 int i=0;
	 int *p;
	 
	 if(numsSize<=0||nums==NULL)
         return 0;	
         
     p = (int *) malloc(sizeof(int)*(numsSize));
     
     p[0] = nums[0];
     p[1] = max(nums[0],nums[1]);
     
     for(i=2;i<numsSize;i++)
     {
     	p[i] = max(p[i-2]+nums[i],p[i-1]);
	 }
	 

	 return p[i-1];
} 



int rob(int* nums, int numsSize) 
{
     
     int ret =0;
	 if(numsSize==1)
     	return nums[0];
     if(numsSize==2) 
     	return max(nums[0],nums[1]);
    	
     return rob1(nums,numsSize-1);
} 

int main()
{
	int exp[0] ;
	int exp2[5] = {2,7,9,3,1};
	int ret;
	
	ret = rob2(exp,4);
	printf("Result is %d\n",ret);
	
	return 0;
} 
