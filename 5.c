#include<stdio.h>
int a[5005],b[5005]={0};
int answer(int n);
void scanr(int n);
int maxinR(int n);
void scanr(int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
int maxinR(int n)
{
	int i,max=0;
	for(i=1;i<n-1;i++)
	{
		if(a[i]<a[n])
		{
			if(max<answer(i))
			{
				max=answer(i);
			}
		}
	}
	return max;
}
int answer(int n)
{
	if(b[n]!=0)
		return b[n];
	if(n==1)
	{
		b[n]=1;
		return b[n];
	}
	b[n]=1;
	b[n]+=maxinR(n);
	return b[n];
}
int main()
{
	int n,i;
	scanf("%d",&n);
	scanr(n);
	int ans=answer(n);
	for (i = 0; i < n; ++i)
	{
		printf("%d ",b[i] );
	}
	printf("\n");
	printf("%d\n",ans );
	return 0;
}
