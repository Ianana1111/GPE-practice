#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void calcu(int h, int m){
    for(int i=1; i<=1440; i++){
        int tmp = 0;
        m+=1;
        tmp = m/60;
        m%=60;
        h+=tmp;
        h%=24;
        //cout << h << ' ' << m << '\n';
        if(h==0){
            int test = m/10;
            int hi = m/10, lo = m%10;
            if(hi==lo || test==0){
                cout << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m;
                return;
            }
        }else if((h/10)==0){
            int hi = h%10, lo = m%10;
            if(hi==lo){
                cout << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m;
                return;
            }
        }else{
            if((h/10)==(m%10) && (h%10)==(m/10)){
                cout << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m;
                return;
            }   
        }
    }
    return;
}

int main(){
    //ios;
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        s+=':';
        int size = s.size();
        int tmp = 0, h = 0, m = 0;
        for(int i=0; i<size; i++){
            if(s[i]==':'){
                if(i==2) h = tmp;
                else  m = tmp;
                tmp = 0;
            }else{
                tmp*=10;
                tmp+=(s[i]-'0');
            }    
        }
        calcu(h, m);
        cout << '\n';
    }
}