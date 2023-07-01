#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    int n; 
    vector<int> comp;
    map<int ,int> rec;
    while(cin >> n){
        comp.resize(n);
        rec.clear();
        for(int i=0; i<n; i++){
            cin >> comp[i];
            rec[comp[i]]++;
        }
        int mid = n/2;
        sort(comp.begin(), comp.end());
        if(n%2){
            cout << comp[mid] << " " << rec[comp[mid]] << " ";
            cout << 1 << '\n';
        }else{
            cout << comp[mid-1] << " ";
            if(comp[mid]==comp[mid-1]){
                cout << rec[comp[mid-1]] << " " << 1 << '\n';
            }else{
                cout << rec[comp[mid-1]] + rec[comp[mid]] << " ";
                cout << comp[mid] - comp[mid-1] + 1 << '\n';
            }
        }
    }
    return 0;
} //  1 4 8 10 11
// 1 8 8 8 10
