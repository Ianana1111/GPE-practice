#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_wiht_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

class contestant{
    public:
        int number = 0, times_pro[10]={0}, sum=0, sum_penal=0;
};

int main(){
    int n; cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    while(n--){
        vector<contestant> contest;
        map<int, int> check;
        while(getline(cin, s)){
            if(s=="") break;
            vl rec;
            int size = s.size();
            int tmp = 0;
            char word = ' ';
            for(int i=0; i<size; i++){
                if(isdigit(s[i])){
                    tmp*=10;
                    tmp+=s[i];
                }else if(isalpha(s[i])){
                    if(check.count(rec[0])){

                    }else{
                        
                    }
                    if(s[i]=='I'){
                        contest[rec[0]].times_pro[rec[1]]++;
                    }else if(s[i]=='C'){
                        contest[rec[0]].sum_penal+=(rec[2]+20*contest[rec[0]].times_pro[rec[1]]);
                        contest[rec[0]].sum++;
                    }
                }else{
                    rec.pb(tmp);
                    tmp = 0;
                }
            }
        }
    }
}