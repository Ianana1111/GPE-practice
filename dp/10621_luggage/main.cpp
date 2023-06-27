#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back
#define mp make_pair

void solve(){
    string s; getline(cin, s);
    vl nums;
    vl record(202, 0);
    int size = s.size();
    int sum = 0;
    int tmp=0;
    for(int i=0; i<size; i++){
        if(isdigit(s[i])){
            tmp*=10;
            tmp+=(s[i]-'0');
        }else{
            sum+=tmp;
            nums.pb(tmp);
            tmp = 0;
        }
    }
    sum+=tmp;

    if(sum%2){
        cout << "NO" << '\n';
        return;
    }
    size = nums.size();
    sort(nums.begin(), nums.end());
    record[0] = 1;
    for(int i=0; i<size; i++){
        for(int j=200; j>=nums[i]; j--){
            if(record[j-nums[i]]==1){
                record[j] = 1;
            }
        }
    }
    if(record[sum/2]) cout << "YES" <<'\n';
    else cout << "NO" << '\n';
    return;
}

int main(){
    ios;
    int n; cin >> n;
    string space;
    getline(cin, space);
    while(n--){
        solve();
    }
    return 0;
}