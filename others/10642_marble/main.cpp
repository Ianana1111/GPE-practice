#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define f first 
#define s second

int main(){
    ll n;
    pll rec[2];
    while(cin >> n && n){
        ll c1, c2, n1, n2;
        cin >> c1 >> n1;
        cin >> c2 >> n2;
        ll now, rem, div;
        bool check = false;
        if(c1*n2<c2*n1){
            ll now = n/n1, rem = n%n1;
            div = n2;
            ll count = rem/n2;
            rem%=n2;
            while(n-rem>=0){
                if(rem%div==0){
                    cout << now << " " << count << '\n';
                    check = true;
                    break;
                }
                count++;
                rem+=n1;
                now--;
            }
        }else if(c1*n2>c2*n1){
            ll now = n/n2, rem = n%n2;
            div = n1;
            ll count = rem/n1;
            rem%=n1;
            while(n-rem>=0){
                if(rem%div==0){
                    cout << count << " " << now << '\n';
                    check = true;
                    break;
                }
                count++;
                rem+=n2;
                now--;
            }
        }else{
            if(n1>n2){
                ll now = n/n1, rem = n%n1;
                div = n2;
                ll count = rem/n2;
                rem%=n2;
                while(n-rem>=0){
                    if(rem%div==0){
                        cout << now << " " << count << '\n';
                        check = true;
                        break;
                    }
                    count++;
                    rem+=n1;
                    now--;
                }
            }else{
                ll now = n/n2, rem = n%n2;
                div = n1;
                ll count = rem/n1;
                rem%=n1;
                while(n-rem>=0){
                    if(rem%div==0){
                        cout << count << " " << now << '\n';
                        check = true;
                        break;
                    }
                    count++;
                    rem+=n2;
                    now--;
                }
            }
        }
        if(check) continue;
        else cout << "failed" << '\n';
    }
} 