/*
By Sanket Singh
*/
#include <iostream>
using namespace std;
bool NaiveSearch(string text, string pattern){
        int i=0;
        int j=0;
        int k = 0;
        while(i < text.size() && j < pattern.size()){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        }
        if(j == pattern.size()){
            return true;
        }
        return false;
    }
int main(int argc, char const *argv[])
{
	/* code */
	string str = "abcxabcdabcdabcy";
    string subString = "abcdabc";
    cout<<NaiveSearch(str, subString);
	return 0;
}
