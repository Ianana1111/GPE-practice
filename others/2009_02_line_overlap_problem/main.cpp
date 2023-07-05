#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define f first
#define s second

bool compare(pll a, pll b){
    return a.f<b.f || (a.f==b.f && a.s<b.s);
}

int main(){
    string c;
    vll rec;
    vll pos;
    while(getline(cin, c) && c!="."){
        ll a, b;
        stringstream ss;
        ss << c; ss >> a >> b;
        rec.pb(mp(a, b));
        pos.pb(mp(a, 0));
        pos.pb(mp(b, 1));
    }
    sort(rec.begin(), rec.end(), compare);
    sort(pos.begin(), pos.end(), compare);
    vl tmp;
    int size = pos.size();
    for(int i=0; i<size; i++){
        if(pos[i].s==0){
            tmp.pb()
        }
    }
}

// 5   120
// 75  325
// 100 255
// 325 500
int calculateOverlappingLength(const std::vector<LineSegment>& segments) {
    int totalLength = 0;
    int currentEnd = segments[0].end;

    for (size_t i = 1; i < segments.size(); i++) {
        if (segments[i].start <= currentEnd) {
            // Found an overlapping segment
            currentEnd = std::max(currentEnd, segments[i].end);
        } else {
            // Non-overlapping segment found, add the overlapping length to the total
            totalLength += currentEnd - segments[i - 1].start;
            currentEnd = segments[i].end;
        }
    }

    // Add the last overlapping length to the total
    totalLength += currentEnd - segments.back().start;

    return totalLength;
}