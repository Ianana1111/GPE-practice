#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>

int arr[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int ans = 0, pos;

void count(int money){
    if(money==0) {
        ans++;
        return;
    }else if(money>0){
        for(int i=pos; i<11; i++){
            if(money-arr[i]>=0){
                count(money-arr[i]);
            }
        }
    }
    return;
}

int main(){
    double input;
    while(cin >> input){
        if(input==0.00) return 0;
        ans = 0;
        int money = input*100;
        for(int i=0; i<11; i++){
            if(money/arr[i]>=1){
                pos = i;
                break;
            }
        }
        cout << pos << '\n';
        count(money);
        cout << input << " " << ans << '\n';
    }
    return 0;
}
// 20
// 