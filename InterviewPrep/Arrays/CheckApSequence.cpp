#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 
 using namespace std;
 
 // ------------------------------------------------------
 bool checkAP(vector<int> &arr)
 {
     // write your code here
     sort(arr.begin(), arr.end());
     int x = arr[0] - arr[1];
     for(int i=1;i<arr.size()-1;i++) {
         if(arr[i]-arr[i+1]!=x) return false;
     }
     return true;
 }
 // ------------------------------------------------------
 
 // Do not change the main Method
 int main()
 {
     int n = 0;
     cin >> n;
     vector<int> num(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> num[i];
     }
     if (checkAP(num))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
 
     return 0;
 }