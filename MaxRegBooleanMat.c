#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isSafe(int i,int j,int rows, int cols, int mat[][cols], int visited[][cols])    {
    return i >= 0 && j >= 0 && i < rows && j < cols && mat[i][j]==1 && visited[i][j]==0;
}

void dfs(int rows, int cols,int mat[][cols], int visited[][cols],int i, int j,int *count) {
    
    visited[i][j]=1;
    *count+=1;
    
    int x[8]={-1,-1,-1,0,1,1,1,0};
    int y[8]={-1,0,1,1,1,0,-1,-1};
    int k;
    for(k=0; k<8; k++)  {
        //printf("%d,%d\n",i,j);
        if(isSafe(i+x[k],j+y[k],rows,cols,mat,visited))   {
            dfs(rows,cols,mat,visited,i+x[k],j+y[k],count);
        }
    }
}

int largestRegion(int rows, int cols, int mat[][cols])  {
    int visited[rows][cols];
    int i,j,count,maxRegion=INT_MIN;
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++)
            visited[i][j]=0;
    }
    
    for(i=0; i<rows; i++)   {
        for(j=0; j<cols; j++)   {
            count=0;
            if(!visited[i][j] && mat[i][j]==1)
                dfs(rows,cols,mat,visited,i,j,&count);
            if(maxRegion < count)
                maxRegion = count;
        }
    }
    return maxRegion;
}

int main() {
	
	int i,j,t,rows,cols;
	scanf("%d",&t);
	while(t--)  {
	    scanf("%d",&rows);
	    scanf("%d",&cols);
	    int mat[rows][cols];
	    for(i=0; i<rows; i++)   {
	        for(j=0; j<cols; j++)
	            scanf("%d",&mat[i][j]);
	    }
	    printf("%d\n",largestRegion(rows,cols,mat));
	}
	/*int mat[rows][cols]={{0,0,0,0,0,0,0,0},
	                     {0,0,0,0,0,0,0,0},
	                     {0,0,0,0,1,0,0,0},
	                     {0,0,0,0,0,1,0,0},
	                     {0,0,0,0,0,0,1,0},
	                     {0,0,0,0,0,0,0,0},
	                     {0,0,0,0,0,0,0,0},
	                     {0,0,0,0,0,0,0,0}};
    */
    
	return 0;
}
