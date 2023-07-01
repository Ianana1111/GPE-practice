#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define mp make_pair
#define vll vector<pair<ll, ll>>

int main(){
    ios;
    int n; 
    while(cin >> n && n){
        //            上 下 左 右 前 後
        int arr[6] = {1, 6, 3, 4, 2, 5};
        for(int i=0; i<n; i++){
            string s; cin >> s;
            if(s=="north"){
                int tmp1 = arr[0], tmp2 = arr[1];
                arr[0] = arr[5]; 
                arr[1] = arr[4]; 
                arr[5] = tmp2;
                arr[4] = tmp1;
            }else if(s=="south"){
                int tmp1 = arr[0], tmp2 = arr[1];
                arr[0] = arr[4]; 
                arr[1] = arr[5]; 
                arr[5] = tmp1;
                arr[4] = tmp2;
            }else if(s=="east"){
                int tmp1 = arr[0], tmp2 = arr[1];
                arr[0] = arr[2]; 
                arr[1] = arr[3]; 
                arr[2] = tmp2;
                arr[3] = tmp1;
            }else if(s=="west"){
                int tmp1 = arr[0], tmp2 = arr[1];
                arr[0] = arr[3]; 
                arr[1] = arr[2]; 
                arr[2] = tmp1;
                arr[3] = tmp2;
            }
        }
        cout << arr[0] << '\n';
    }
    return 0;
}
