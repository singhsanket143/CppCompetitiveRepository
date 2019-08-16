#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 // -------------------------------------------
 bool isFrequencyEqual(string &str)
 {
     // write your code here
     int arr[26] = {0};
     for(int i=0;i<str.size();i++) {
         arr[str[i]-'a']++;
     }
     int distinctChar = 0;
     for(int i=0;i<26;i++) {
         if(arr[i] > 0) distinctChar++;
     }
     int count = 0;
     for(int i=0;i<26;i++) count+=arr[i];
     if((count-1)%distinctChar == 0) return true;
     else return false;
     
 }
 // -------------------------------------------
 
 int main()
 {
     string s;
     cin >> s;
 
     if (isFrequencyEqual(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
 
     return 0;
 }