#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    int arr[101];
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;
    for(int i=1; i<=2; i++){
        for(int j=1; j<101; j++){
            if(arr[j-i]!=0){
                arr[j]+=arr[j-i];
            }
        }
    }
    int n; cin >> n;
    cout << arr[n] << '\n';
}