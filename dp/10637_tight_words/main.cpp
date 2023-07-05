#include <cstdio>
#include <cstring>
#define N 110
#define M 15
double dp[N][M];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0) { printf("100.00000\n"); continue; }
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=m; i++) dp[1][i]=1;
        for(int i=2; i<=n; i++) //位
            for(int j=0; j<=m; j++) //数字
            {
                if(j==0) dp[i][0]=dp[i-1][0]+dp[i-1][1];
                else if(j==m) dp[i][m]=dp[i-1][m]+dp[i-1][m-1];
                else for(int k=j-1; k<=j+1; k++) dp[i][j]+=dp[i-1][k];
            }
        double s=1,a=0;
        for(int i=0; i<=m; i++) a+=dp[n][i];
        a*=100;
        for(int i=1; i<=n; i++) s*=(m+1);
        printf("%.5f\n",a/s);
    }
    return 0;
}