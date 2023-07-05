#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define cos60 0.5
#define eps 1e-9

int main(){
    ios
    double n;
    double pi = acos(-1.0);
    while(cin >> n){
        double hr = n/2;
        double tmp = n*n*pi/6 - sqrt(3)*hr*hr;
        double area_sma = n*n*pi/4 - (n*n*pi/6) - tmp;
        double area_big = n*n - n*n*pi/4;
        double ans1 = area_big - area_sma;
        double ans2 = area_big - ans1*2;
        double ans3 = n*n - 4*ans1 - 4*ans2;
        cout << fixed << setprecision(3) << ans3 << " " << ans2*4 << " " << ans1*4 << '\n';
    }
    return 0;
}