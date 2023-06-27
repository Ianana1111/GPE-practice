#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int main(){
    ios;
    string s;
    while(getline(cin, s)){
        if(s==".")return 0;
        reverse(s.begin(), s.end());
        s+="\n";
        int size = s.size();
        vector<ll> nums;
        bool check = true;
        int mul = 1;
        int num = 0;
        for(int i=0; i<size; i++){
            if(isdigit(s[i])){
                num+=mul*(s[i]-'0');
                mul*=10;
                //cout << num << '\n';
            }else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%'){
                int a, b;
                if(nums.size()<2){
                    cout << "illegal" << '\n';
                    check = false;
                    break;
                }
                // int size = nums.size();
                // for(int i=0; i<size; i++) cout << nums[i] << " \n"[i==size-1];
                b = nums.back(); nums.pop_back();
                a = nums.back(); nums.pop_back();
                int tmp = 0;
                if(s[i]=='+') tmp = a+b;
                else if(s[i]=='-') tmp = b-a;
                else if(s[i]=='*') tmp = a*b;
                else if(s[i]=='/') tmp = b/a;
                else if(s[i]=='%') tmp = b%a;
                
                nums.push_back(tmp);
            }else{
                if(num) nums.push_back(num);
                mul = 1;
                num = 0;
            }
        }
        //cout << s << '\n';
        if(check)cout << nums[0] << '\n';
    }
}