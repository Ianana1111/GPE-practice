#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
#include<algorithm>
#define max(a,b)   (a>b?a:b)
#define min(a,b)   (a<b?a:b)
#define swap(a,b)  (a=a+b,b=a-b,a=a-b)
using namespace std;
typedef long long int LL;
const int MAXL(1e6);
const int INF(0x3f3f3f3f);
const int MAX(1e8);
const int mod(1e9+7);
LL ans[MAXL+50];
int main()
{
    //ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n&&n)
    {
        ans[0]=1;
        int len=0;
        for(int i=n+2;i<=2*n;i++)
        {
            int temp=0;
            for(int j=0;j<=len;j++)
            {
                ans[j]=ans[j]*i+temp;
                temp=ans[j]/MAX;
                ans[j]%=MAX;
            }
            if(temp>0)
                ans[++len]=temp;
        }
        printf("%lld",ans[len]);
        for(int i=len-1;i>=0;i--)
            printf("%08lld",ans[i]);
        cout<<endl;
    }
} //  1   60392960
// ans[0] = 12;
//  10*
// 11 47466240