#include <iostream>
  #include <string>
  #include <vector>
  #include <unordered_set>
  #include <climits>
  
  using namespace std;
  
  //----------------------------------------
  bool isContiguous(vector<int> &arr)
  {
      // Write your code here
      unordered_set<int> mp;
      int min_el = INT_MAX;
      int max_el = INT_MIN;
      for(int i=0;i<arr.size();i++) {
          if(min_el > arr[i]) {
              min_el = arr[i];
          }
          if(max_el < arr[i]) {
              max_el = arr[i];
          }
          mp.insert(arr[i]);
      }
      for(int i=min_el+1;i<=max_el;i++) {
          if(mp.find(i-1)==mp.end()) return false;
      }
      return true;
      
  }
  //----------------------------------------
  
  int main()
  {
      int n = 0;
      cin >> n;
      vector<int> num(n, 0);
      for (int i = 0; i < n; i++)
      {
          cin >> num[i];
      }
  
      if (isContiguous(num))
      {
          cout << "true" << endl;
      }
      else
      {
          cout << "false" << endl;
      }
  
      return 0;
  }