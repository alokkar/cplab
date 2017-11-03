#include<stdio.h>
clearAttack(int arr[][], int row, int col, int n)
{
	int i,j;
	for (i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==row || j==col || i+j==row+col || j-i==col-row)
				arr[i][j]=0;
	arr[row][col]=1;
}
checkMOandO(int a[][],int n)
{
	int i,j,ch=0,count=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==0)
			{
				ch=1;
				return 0;
			}
	if(ch=0)
	{
		for(i=0;i<n;i++)
                	for(j=0;j<n;j++)
                        	if(a[i][j]==1)
					count++;
		if(count==n)
			return 1;
		else
			return 0;
	}
}
orig(int temp[][],int a[][],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=temp[i][j];
}
queen(int a[][],int n)
{	
	int i,j,temp[20][20];
	if(checkMOandO(a,n)==1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}
		return;
	}
	else
	{
		for(i=0;i<n;i++)
                	for(j=0;j<n;j++)
                        	temp[i][j]=a[i][j];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=1;
				clearAttack(a,i,j,n);
				queen(a,n);
				orig(temp,a,n);
			}
		}
	}
}
int main()
{
	int a[20][20],n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0-1;
	queen(a,n);
	return 0;
}
