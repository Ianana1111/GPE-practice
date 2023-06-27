#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

int gcd(int a, int b, int &x, int &y){
    //if(a>b) swap(a, b);
    if(a%b == 0) {
        x = 0; y = 1;
        return b;
    }else{
        int r, tx, ty;
        r = gcd(b, a%b, tx, ty);
        x = ty;
        y = tx - a/b*ty;
        return r;
    }
}

int main(){
    int a, b, x, y;
    while(cin >> a && cin >> b){
        int rec = gcd(a, b, x, y);
        cout << x << " " << y << " " << rec << '\n';

    }
    return 0;
}