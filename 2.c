#include <stdio.h>
int main()
{
	int n,m,ch=0,i,prevj,max,j,a[1000005],count[1000005]={0},q;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
			ch++;
	}
	if(m>=ch)
	{
		printf("%d\n",n);
		return 0;
	}
	if(ch==n)
	{
		printf("%d\n",m);
		return 0;
	}
	if(ch==n-1)
	{
		printf("%d\n",m+1 );
		return 0;
	}
	for(j=0;j<n;j++)
	{
		if(q==m && a[j]!=1)
			break;
		if(a[j]==0)
		{
			q++;
		}
	}
	count[0]=j;
	prevj=j;
	for(i=1;i<n;i++)
	{
		if(a[i-1]==1)
		{
			count[i]=count[i-1]-1;
			for(j=prevj;j<n;j++)
			{
				if(a[j]==0)
					break;
			}
			count[i]+=j-prevj;
		}
		else
		{
			count[i]=count[i-1]-1;
			for(j=prevj;j<n;j++)
			{
				if (a[j]==0)
				{
					j++;
					break;
				}
			}
			count[i]+=j-prevj;
			prevj=j;
			for(j=prevj;j<n;j++)
			{
				if (a[j]==0)
				{
					break;
				}
			}
			count[i]+=j-prevj;
		}
		prevj=j;
	}
	max=0;
	for (int i = 0; i < n; i++)
	{
		printf("%d ",count[i] );
		if(max<count[i])
			max=count[i];
	}
//	printf("\n");
	printf("%d\n",max);
	return 0;
}