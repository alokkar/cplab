#include<stdio.h>
int mat[50][50]={0};
void attack(int row,int col,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==row || j==col || i+j==row+col || j-i==col-row)
				mat[i][j]-=1;
	return;
}
void refill(int row, int col,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==row || j==col || i+j==row+col || j-i==col-row)
				mat[i][j]+=1;
	return;
}
int solve(int n,int i)
{
	int t,j;
	if(i==n)
		return 1;
	else
	{
		for(j=0;j<n;j++)
			if(mat[i][j]==0)
			{
				attack(i,j,n);
				t=solve(n,i+1);
				if(t==1)
					return 1;
				else
					refill(i,j,n);
			}
	}
	return -1;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int p=solve(n,0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(mat[i][j]==-1)
				printf("1 ");
			else
				printf("0 ");
		printf("\n");
	}
	return 0;
}
