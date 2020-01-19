/*package whatever //do not write package name here */

import java.io.*;

class GFG {
    public static int max(int a, int b) {
        return a>b?a:b;
    }
    public static int SolveEggDropping(int n, int k)    {
        int res=0,minVal;
        int sol[][] = new int[k+1][n+1];
        for(int j=0; j<=n; j++)  {
            sol[0][j] = 0;
            sol[1][j] = j;
        }
        
        for(int i=1; i<=k; i++)  {
            sol[i][0] = 0;
            sol[i][1] = 1;
        }
        
        for(int i = 2; i<=k; i++)    {
            for(int j = 2; j<=n; j++)    {
                minVal = Integer.MAX_VALUE;
                for(int x = 1; x<=j; x++)   {
                    res = 1+max(sol[i-1][x-1],sol[i][j-x]);
                    if(res < minVal)    {
                        minVal = res;
                    }
                }
                sol[i][j] = minVal;
            }
        }
        for(int i = 0; i<=k; i++)    {
            for(int j = 0; j<=n; j++)    {
                System.out.print(sol[i][j]+" ");
            }
            System.out.println();
        }
        return sol[k][n];
        
    }
	public static void main (String[] args) {
		System.out.println("Minimum number of trials = "+SolveEggDropping(100,5));
	}
}
