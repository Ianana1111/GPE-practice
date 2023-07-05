#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define eps 1e-9

int main(){ 
  int n;
  double pay[1005], average, high_exchange, low_exchange;

  while( scanf( "%d", &n ) != EOF && n ){
    average = 0;
    for( int i = 0 ; i < n ; i++ ){
      scanf( "%lf", &pay[i] );
      average += pay[i];
    }

    average = ((double)(int)(average*100/n))/100;
    //cout << average << '\n';
    high_exchange = 0;
    low_exchange = 0;

    for( int i = 0 ; i < n ; i++ ){
      if( average < pay[i] ) high_exchange += ( pay[i] - average );
      if( average > pay[i] ) low_exchange += ( average - pay[i] );
    }
    printf( "$%.2lf\n", ( high_exchange < low_exchange )? high_exchange : low_exchange );
  }
  return 0;
}