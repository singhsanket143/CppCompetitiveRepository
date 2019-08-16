#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 // --------------------------------------
 bool isIsogram(string &data)
 {
     // write your code here
     int arr[26] = {0};
     for(int i=0;i<data.size();i++) {
         if(arr[data[i]-'a'] == 0) arr[data[i]-'a']++;
         else return false;
     }
     return true;
 }
 // --------------------------------------
 
 int main()
 {
     string s;
     cin >> s;
 
     if (isIsogram(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }