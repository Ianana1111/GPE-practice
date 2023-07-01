#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

map<string, int> rec;

int main(){
    int a, b; cin >> a >> b;
    for(int i=0; i<a; i++){
        string x; int y;
        cin >> x >> y;
        rec[x] = y;
    }
    string line;
    getline(cin, line);
    while(b--){
        string input;
        int ans=0;
        while(getline(cin, input) && input!="."){
            int size = input.size(); 
            string tmp="";
            for(int i=0; i<size; i++){
                if(isalpha(input[i])){
                    tmp+=input[i];
                }else if(input[i]==' ' && tmp!=""){
                    if(rec.count(tmp)){
                        ans+=rec[tmp];
                        cout << tmp << " ";
                    }
                    tmp = "";
                }
            }
            if(rec.count(tmp)) ans+=rec[tmp];
        }
        cout << ans << '\n';
    }
}