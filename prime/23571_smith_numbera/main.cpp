#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

int arr[32001];

int calcu(int x){
    int ans = 0;
    while(x>0){
        ans+=(x%10);
        x/=10;
    }
    return ans;
}

int main(){
    ios;
    vl prim;
    memset(arr, 0, sizeof(arr));
    for(int i=2; i<=32000; i++){
        if(!arr[i]){
            prim.pb(i);
            for(int j=2*i; j<=32000; j+=i)
                arr[j] = 1;
        }
    }
    int n; cin >> n;
    int size = prim.size();
    while(n--){
        int k; cin >> k;
        for(int i=k+1;;i++){
            if(*lower_bound(prim.begin(), prim.end(), i)==i) continue;
            int sum1=0, sum2=0, tmp = i, count = 0;
            sum1 = calcu(tmp);
            tmp = i;
            while(tmp>1 && count<size){
                if(tmp%prim[count]==0){
                    int rep = prim[count], wait=0;
                    wait = calcu(rep);
                    while(tmp%prim[count]==0){
                        sum2+=wait;
                        tmp/=prim[count];
                    }
                }
                count++;
            }
            if(tmp==i) continue;
            if(tmp>1) sum2 += calcu(tmp);
            if(sum1==sum2){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}