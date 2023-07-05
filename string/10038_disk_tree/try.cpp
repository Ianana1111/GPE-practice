#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define f first 
#define s second

struct Tree{
    int sz;
    map<string, int> son[50005];
    void init();
    void in(string s);
    void out(int u, int n);
}tree;

void Tree::init(){
    sz = 1;
    son[0].clear();
}

void Tree::in(string s){
    string tmp = "";
    int size = s.size(), u = 0;
    for(int i=0; i<size; i++){
        if(s[i]=='\\'){
            if(!son[u].count(tmp)){
                son[sz].clear();
                son[u][tmp]= sz++;
            }
            u = son[u][tmp];
            tmp = "";
        }else  
            tmp+=s[i];
    }
}

void Tree::out(int u, int n){
    for(auto &c: son[u]){
        for(int i=0; i<n; i++)
            cout << " ";
        cout << c.f << '\n';
        out(c.s, n+1);
    }
}

int main(){
    int n;
    while(cin >> n && n){
        string s;
        tree.init();
        for(int i=0; i<n; i++){
            cin >> s;
            s+='\\';
            tree.in(s);
        }
        tree.out(0, 0);
    }
    return 0;
}