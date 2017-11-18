#include <stdio.h>
int a[1009],k;
int mininR(int end,int start)
{
	int i,min;
	if(end==start+1)
		return end;
	if(start<0)
		return -1;
	min=10000;
	for(i=end;i>start;i--)
	{
		if(a[i]<0)
		{
			return i;
		}
		if(a[i]<min)
			min=a[i];
	}
	for(i=end;i>start;i--)
	{
		if (a[i]==min)
		{
			break;
		}
	}
	if(i==end)
	{
		return mininR(end-1,start);
	}
	else
		return i;
}
int sumtill(int end,int start)
{
	int sum=0,i;
	for(i=end;i>start;i--)
		sum+=a[i];
	return sum;
}
int answer(int n)
{
	if(n<=0)
		return 0;
	int l,ans;
	l=mininR(n,n-k);
	printf("%d\n",l);
	ans=sumtill(n,l)+answer(l-1);
	return ans;
}
int main()
{
	int n,i,ans;
	scanf("%d%d",&n,&k);
	for (i = 1;i <=n; i++)
	{
		scanf("%d",&a[i]);
	}
	if(k==1)
	{
		printf("0\n");
		return 0;
	}
	ans=answer(n);
	printf("%d\n",ans);
	return 0;
}