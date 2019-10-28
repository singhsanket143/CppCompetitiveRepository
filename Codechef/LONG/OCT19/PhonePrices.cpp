#include "iostream";
using namespace std;

int main(int argc, char const *argv[])
{
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    int *arr = new int[n]();
    for(int i=0;i<n;i++) {
      cin>>arr[i];
    }
    int count = 1;
    for(int i = 1; i < n;i++) {
      bool status = false;
      for(int j = i-1; j >=0 and j >= i - 5; j--) {
        if (arr[j] <= arr[i]) {
          status = true;
          break;
        }
      }
      if(!status) count++;
    }
    cout<<count;
  }
  return 0;
}
