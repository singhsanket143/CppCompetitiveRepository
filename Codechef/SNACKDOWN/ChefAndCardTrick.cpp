#include<iostream>
#define ll long long int
using namespace std ;
int main()
{
  int t;
  cin >> t ;
  while(t--)
  {
    long long int size = 0 ;
    cin >> size ;
    long long int prev = 0 ;
    long long int next = 0 ;
    long long int count = 0 ;
    long long int mid = -1;
    ll arr[size];
    cin>>prev;
    arr[0] = prev;
    for(long long int j = 1 ; j < size ; j++ ) {
      cin>>next ;
      arr[j] = next;
      if( prev > next ) {
          if(count == 0) mid = j;
          count++ ;
      }
      prev = next ;
    }

    // cout<<count<<endl;
    if(count > 1) {
      cout<<"NO"<<endl;
    } else {
      if(arr[0] < arr[size-1] and count!=0) {
        cout<<"NO"<<endl;
      } else {
        cout<<"YES"<<endl;
      }
    }
  }
  return 0 ;
}