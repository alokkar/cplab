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


void print_final(int n){

	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(mat[i][j]==-1)
				printf("1 ");
			else
				printf("0 ");
		printf("\n");
	}
	printf("\n");

}
void solve(int n,int i)
{
	int t,j,p,q;
	if(i==n){
		print_final(n);
		return;
	}
	else
	{
		for(j=0;j<n;j++){
			if(mat[i][j]==0)
			{
				attack(i,j,n);
				solve(n,i+1);
				refill(i,j,n);
			}
		}

		return;
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	solve(n,0);
	return 0;
}
