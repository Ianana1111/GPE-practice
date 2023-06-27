#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  int N, m, turnoff;

  while( scanf( "%d", &N ) != EOF && N != 0 ){
    N--;
    for( m = 1 ; m < N ; m++ ){
      turnoff = 0;
      for( int i = 1 ; i <= N ; i++ )
        turnoff = (turnoff + m) % i;
      if( turnoff == 11 ) break;
    }
    printf( "%d\n", m );
  }
  return 0;
}