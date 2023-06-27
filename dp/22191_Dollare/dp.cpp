#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

//int arr[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int arr[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main(){
    ios;
    ll visit[30001];
    memset(visit, 0, sizeof(visit));
    visit[0] = 1;
    for(int i=0; i<11; i++){
        for(int j=arr[i]; j<30001; j++){
            if(visit[j-arr[i]]!=0){
                visit[j]+=visit[j-arr[i]];
            }
        }
    }
    double input; 
    while(cin >> input){
        if(input==0.00) return 0;
        int money = input*100;
        cout << setw(6)<< setprecision(2) << fixed<< input;
        cout << setw(17) << visit[money] << '\n';
    }
}