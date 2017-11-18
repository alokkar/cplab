#include <stdio.h>
#include <string.h>
char s[100005];
int k,ls,m[1000005]={0};
void goodstring()
{
	if(k>ls)
	{
		printf("%s\n",s);
		return;
	}
	int i,j,ch,alok=0,hola=0,q;
	/*for(i=0;i<ls;i++)
		printf("%d ",m[i] );
	printf("\n");*/
	for(i=0;i<ls;i++)
	{
		if(m[i]==0)
		{
			ch=0;
			for(q=0, j=0;q<ls && j<k;)
			{
				if(m[i+q]==0)
				{
					if(s[i]!=s[i+q])
					{
						ch=1;
						break;
					}
					else
					{
						j++;
						q++;
					}
				}
				else
					q++;
			}
			if(ch==0)
			{
				alok=1;
				break;
			}
		}
		else
			i++;
	}
	if(alok==1)
	{
		for(i=0;i<ls;i++)
		{
			if(m[i]==0)
			{		
				ch=0;
				for(j=0, q=0 ;j<k && q<ls;)
				{
					if(m[i+q]==0)
					{
						if(s[i]!=s[i+q])
						{
							ch=1;
							break;
						}
						else
						{
							q++;
							j++;
						}
					}
					else q++;
				}
				if(ch==0)
				{
					for(j=0, q=0 ;j<k && q<ls;)
					{
						if(m[i+q]==0)
						{
							if(s[i]!=s[i+q])
							{
								ch=1;
								break;
							}
							else
							{
								m[i+q]=1;
								q++;
								j++;
							}
						}
						else q++;
					}
				}
			}	
			else
				i++;
		}
		goodstring();
	}
	else
	{
		for(i=0;i<ls;i++)
		{
			if(m[i]==0)
			{	
				printf("%c",s[i]);
				hola=1;
			}
		}
		if(hola!=1)
			printf("-1");
		printf("\n");

	}
}
int main()
{
	int i;
	scanf("%s",s);
	scanf("%d",&k);
	ls=strlen(s);
	goodstring();
	return 0;
}