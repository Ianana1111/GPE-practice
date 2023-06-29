#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>

int main(){
    int n, m;
    while(cin >> n >> m){
        vl ves(n);
        int l=0, r=0;
        for(int i=0; i<n; i++){
            cin >> ves[i];
            if(ves[i]>l) l = ves[i];
            r+=ves[i];
        }
        while(l<r){
            int mid = (l+r)/2;
            int count=0, rec=0;
            for(int i=0; i<n; i++){
                rec+=ves[i];
                if(rec>mid){
                    count++;
                    rec=ves[i];
                }else if(rec==mid){
                    count++;
                    rec = 0;
                }
            }
            if(rec>0) count++;
            if(count>m) l = mid+1;
            else r = mid;
        }
        cout << l << '\n';
    }
}