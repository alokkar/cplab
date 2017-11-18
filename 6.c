#include <stdio.h>
#include <string.h>
char s[1000005],p[1000005];
int first,last,middle,j,m[1000005]={0},ls,lp,a[1000005],i;

int main()
{
	scanf("%s",s);
	scanf("%s",p);
	ls=strlen(s);
	lp=strlen(p);
	//printf("%d %d\n",ls,lp );
	for (i=0;i<ls;i++)
	{
		scanf("%d",&a[i]);
	}
	//printf("%d %d\n",ls,lp );
	if(lp>ls)
	{
		printf("-1\n");
		return 0;
	}
	first=0;
	last=ls-1;
	while(first<=last)
	{
		middle=(last+first)/2;
		for (i = 0; i <middle; i++)
		{
			m[a[i]-1]=1;
		}
		/*for(i=0;i<ls;i++)
		{
			printf("%d ",m[i] );
		}*/
		//printf("\n");
		//printf("%d %d %d\n",first,middle,last );
		i=0;j=0;
		while(i<ls && j<lp)
		{
			if(m[i]==0)
			{
				if(s[i]==p[j])
				{
					i++;
					j++;
				}
				else 
					i++;
			}
			else
				i++;
		}
		if(j==lp)
		{
			first=middle;
			for(i=0;i<ls;i++)
				m[i]=0;
		}
		else
		{
			last=middle;
			for (i = 0; i < ls; i++)
			{
				m[i]=0;
			}
		}
		if(last-first==1)
		{
			middle=first;
			break;
		}
	}
	printf("%d\n",middle);
	return 0;
}