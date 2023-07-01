#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int t, m, n, q, a[105][105], mx[105][105], x, y, ans;
char c;
 
int main() {
    memset(a, -1, sizeof(a));
    cin >> t;
    while (t--){
        cin >> m >> n >> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> c;
                a[i][j] = (int)c;
                if (i == 0 || j == 0) mx[i][j] = 1;
                else if (a[i][j] == a[i-1][j] && a[i][j] == a[i-1][j-1] && a[i][j] == a[i][j-1]){
                    mx[i][j] = min({mx[i-1][j], mx[i-1][j-1], mx[i][j-1]})+1 ;
                }
                else mx[i][j] = 1;
            }
        }
        cout << m << " " << n << " " << q << "\n";
        while (q--){
            cin >> x >> y;
            ans = 1;
            for (int i = 1; i <= 100; i++){
                if (x+i > m || y+i > n) break;
                if (mx[x+i][y+i] >= ans+2) ans += 2;
                else break;
            }
            cout << ans << "\n";
        }
    }
}