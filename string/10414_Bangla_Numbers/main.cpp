#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    ll n;
    while(cin >> n){
        vector<ll> inter;
        vector<string> unit;
        ll a;
        vector<ll> r;
        int times=0, ans=0;
        if(n>=10000000){
            a = n;
            while(a>=10000000){
                r.push_back(a%10000000);
                a/=10000000;
                ans++;
            }
            for(int i=ans; i>=0; i--){
                if(i!=ans) a = r[i];
                if(a>=100000){
                    inter.push_back(a/100000);
                    a %= 100000;
                    unit.push_back("lakh");
                    times++;
                }
                if(a>=1000){
                    inter.push_back(a/1000);
                    a %= 1000;
                    unit.push_back("hajar");
                    times++;
                }
                if(a>=100){
                    inter.push_back(a/100);
                    a %= 100;
                    unit.push_back("shata");
                    times++;
                }
                if(i>0){
                    inter.push_back(a);
                    unit.push_back("kuti");
                    times++;
                }
            }
            for(int i=0; i<times; i++){
                cout << inter[i] << " " << unit[i] << " ";
            }
            cout << a << '\n';
        }else{
            if(n>=100000){
                inter.push_back(n/100000);
                n %= 100000;
                unit.push_back("lakh");
                times++;
            }
            if(n>=1000){
                inter.push_back(n/1000);
                n %= 1000;
                unit.push_back("hajar");
                times++;
            }
            
            if(n>=100){
                inter.push_back(n/100);
                n %= 100;
                unit.push_back("shata");
                times++;
            }
            cout << times << '\n';
            for(int i=0; i<times; i++){
                cout << inter[i] << " " << unit[i] << " ";
            }
            cout << n << '\n';
        }
    }
    return 0;
}
// 1 4 7 6 5 6  