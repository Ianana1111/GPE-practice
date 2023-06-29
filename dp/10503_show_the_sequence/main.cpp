#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define vc vector<char>
#define pb push_back

int main(){
    ios;
    string s;
    while(getline(cin, s)){
        if(s=="") return 0;
        stringstream ss;
        int num=3;
        ss<<s; ss>>s>>num;
        //cout << num << '\n';
        vl nums; vc ope;
        int tmp = 0, neg = 1, size = s.size();
        // cout << size << '\n';
        for(int i=0; i<size; i++){
            //cout << s[i] << " ";
            if(isdigit(s[i]) || s[i]=='-'){
                if(s[i]=='-') neg*=-1;
                else{
                    tmp*=10;
                    tmp+=(s[i]-'0');
                }
            }else if(s[i]=='*' || s[i]=='+'){
                nums.pb(tmp*neg);
                tmp=0; neg = 1;
                ope.pb(s[i]);
            }else{
                if(tmp!=0){
                    nums.pb(tmp*neg);
                    tmp=0; neg = 1;
                }
            }
        }
        size = nums.size();
        vl rec(num);
        //for(int i=0; i<size; i++) cout << nums[i] << " \n"[i==size-1];
        for(int i=size-1; i>=0; i--){
            if(i==size-1){
                for(int j=0; j<num; j++){
                    rec[j]=nums[i];
                    //cout << rec[j] << " ";
                }    
            }else{
                if(ope[i]=='+'){
                    vl tmp = rec;
                    rec[0] = nums[i];
                    for(int i=1; i<num ;i++){
                        rec[i]=rec[i-1]+tmp[i-1];
                    }
                }else{
                    rec[0] *= nums[i];
                    for(int i=1; i<num ;i++){
                        rec[i]*=rec[i-1];
                    }
                }
            }
        }
        for(int i=0; i<num; i++) cout << rec[i] << " \n"[i==num-1];
    }
    return 0;
}
// 1 1 1
// 2 