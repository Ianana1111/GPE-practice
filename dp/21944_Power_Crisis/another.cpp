#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, m, turnoff;

  while( cin >> N && N ){
    N--;
    for( m = 1 ; m < N ; m++ ){
      turnoff = 0;
      for( int i = 2 ; i <= N ; i++ )
        turnoff = (turnoff + m) % i;
      if( turnoff == 11 ) break;
    }
    cout << m << '\n';
  }
  return 0;
}