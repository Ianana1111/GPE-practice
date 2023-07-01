#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back
#define f first 
#define s second 

class contestant{
    public:
        int num = 0, error[10]={0}, sum=0, sum_penal=0;
        bool done[10] = {false};
};

bool compare(contestant a, contestant b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    if(a.sum_penal != b.sum_penal) return a.sum_penal < b.sum_penal;
    return a.num<b.num;
}

int main(){
    ios;
    int n; cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    while(n--){
        map<int, int> check;
        contestant player[101];
        while(getline(cin, s) && s!=""){
            int num, prob, time;
            char state;
            stringstream ss;
            ss << s;
            ss >> num >> prob >> time >> state;
            check[num] = 1;
            player[num].num = num;
            if(state=='I'){
                player[num].error[prob]+=20;
            }else if(state=='C'){
                if(!player[num].done[prob]){
                    int error = player[num].error[prob];
                    player[num].sum++;
                    player[num].sum_penal+=(time+error);
                    player[num].done[prob] = true;
                    
                }     
            }
        }
        vector<contestant> rec;
        for(auto &iter: check){
            rec.pb(player[iter.f]);
        }
        sort(rec.begin(), rec.end(), compare);
        int size = rec.size();
        for(int i=0; i<size; i++){
            cout << rec[i].num << " " << rec[i].sum << " " << rec[i].sum_penal << '\n'; 
        }
        if(n) cout << '\n';
    }
    return 0;
}
// 1

// 1 2 10 I
// 3 1 11 C
// 1 2 19 R
// 1 2 21 C
// 1 1 25 C
// 2 1 30 R
// 3 2 40 C
// 1 1 41 C