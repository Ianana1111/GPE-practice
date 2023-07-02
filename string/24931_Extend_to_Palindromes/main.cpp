#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define f first 
#define s second 

int main(){
    ios;
    string s;
    while(cin >> s){
        int size = s.size();
        pll pos = mp(0, 0);
        int mx=0;
        for(int i=0; i<size; i++){
            int l=i, r=i, len=0;
            while(s[r+1]==s[i] && r+1<size) r++; //把相臨且相同數字當作中心
            for(int j=1; j<=(size/2); j++){
                if(l-j<0 || r+j==size)break;  // 如果l超出左界，或r超出右界則break
                if(s[l-j]==s[r+j]) len = j;
                else break;
            }
            if(l-len>0 && r+len<size-1) continue; //必須要其中一邊在左或右界才可以形成迴文
            int dif1 = r-l;
            int dif2 = pos.s-pos.f;
            if(dif1+len*2>=dif2+mx*2){  //挑選總長度最長的
                mx = len;
                pos = mp(l, r);
            }
            i=r;
        }
        if(pos.f-mx == 0 && pos.s+mx == size-1){ //如果l==左界 && r==右界，就是原字串
            cout << s << '\n';
            continue;
        }else{  //製作迴文
            string tmp = "";
            int dif = pos.s - pos.f;
            if(pos.f-mx==0){
                for(int i=size-1; i>=(1+dif+mx*2); i--)
                    tmp+=s[i];
                tmp+=s;
            }else{
                tmp+=s;
                for(int i=size-(1+dif+mx*2)-1; i>=0; i--)
                    tmp+=s[i];
            }
            cout << tmp << '\n';
        }
    }
} // 10