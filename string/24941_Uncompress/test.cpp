#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
vector <string> v;
string word = "";
int num = 0;
 
void moveList(string w){
    v.push_back(v.back());
    for (int i = v.size()-2; i > 0; i--){
        v[i] = v[i-1];
    }
    v[0] = w;
}
 
void printWord(){
    cout << word;
    if (v.empty()) {
        v.push_back(word);
    } else moveList(word);
    word = "";
}
 
void printNum(){
    string w = v[num-1];
    cout << w;
    for (int i = num-1; i > 0; i--){
        v[i] = v[i-1];
    }
    v[0] = w;
    num = 0;
}
 
int main() {
    ios;
    while (getline(cin, s)){
        if (s == "0") break;
        s += "\n";
        for (int i = 0; i < s.size(); i++){
            if (isalpha(s[i])) {
                word += s[i];
            } else if (isdigit(s[i])){
                num *= 10;
                num += s[i] - '0';
            } else {
                if (num) printNum();
                if (word != "") printWord();
                cout << s[i];
            }
        }
    }
    return 0;
}