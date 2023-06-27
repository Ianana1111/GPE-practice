#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define mp make_pair
#define vll vector<pair<ll, ll>>

// vector<vector<int>> arr = {{0, 0, 0, 0},
//                       {2, 3, 5, 4,},
//                       {6, 3, 1, 4,},
//                       {2, 6, 5, 1,},
//                       {2, 1, 5, 6,},
//                       {1, 3, 6, 4,},
//                       {5, 3, 2, 4}};

int arr[7][4] = {0, 0, 0, 0,
                 2, 3, 5, 4,
                 6, 3, 1, 4,
                 2, 6, 5, 1,
                 2, 1, 5, 6,
                 1, 3, 6, 4,
                 5, 3, 2, 4};

int main(){
    int n;
    while(cin >> n){
        if(n==0) return 0;
        int now = 1;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            if(s[0]=='n'){
                now = arr[now][2];
                //cout << arr[now][2] << '\n';
            }else if(s[0]=='w'){
                now = arr[now][3];
                //cout << arr[now][3] << '\n';
            }else if(s[0]=='s'){
                now = arr[now][0];
                //cout << arr[now][0] << '\n';
            }else{
                now = arr[now][1];
                //cout << arr[now][1] << '\n';
            }
        }
        cout << now << '\n';
    }
}

//      2 
//    3 1 4 6
//      5    
//