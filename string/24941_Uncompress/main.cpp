#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vs vector<string>

string find(vs &rec, int num){
    int size = rec.size();
    string tmp = rec[size-num];
    rec.erase(rec.begin()+(size-num));
    rec.pb(tmp);
    return tmp;
}

int main(){
    ios;
    string s;
    vs rec;
    while(getline(cin, s) && s!="0"){
        int size = s.size();
        string tmp = "";
        int num = 0;
        for(int i=0; i<size; i++){
            if(isalpha(s[i])){
                tmp+=s[i];
            }else if(isdigit(s[i])){
                num*=10;
                num+=(s[i]-'0');
            }else{
                if(num){
                    string get = find(rec, num);
                    cout << get;
                    num = 0;
                }
                if(tmp!=""){
                    rec.pb(tmp);
                    cout << tmp;
                    tmp = "";
                }
                cout << s[i];
            }
        }
        if(num){
            string get = find(rec, num);
            cout << get;
            num = 0;
        }
        if(tmp!=""){
            rec.pb(tmp);
            cout << tmp;
                    tmp = "";
        }
        cout << '\n';
    }
    return 0;
}