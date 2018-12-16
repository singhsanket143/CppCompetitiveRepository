/*
By Sanket Singh
*/
#include <iostream>
using namespace std;

int* computeTemporaryArray(string pattern, int m){
        int* lps = new int[m];
        int index =0;
        for(int i=1; i < m;){
            if(pattern[i] == pattern[index]){
                lps[i] = index + 1;
                index++;
                i++;
            }else{
                if(index != 0){
                    index = lps[index-1];
                }else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;
}

bool KMP(string text, string pattern, int m, int n){
        
        int *lps = computeTemporaryArray(pattern, m);
        int i=0;
        int j=0;
        while(i < n and j < m){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        if(j == m){
            return true;
        }
        return false;
}
int main(int argc, char const *argv[])
{
	string str = "abcxabcdabcdabcy";
    string subString = "abcdabc";
    cout<<KMP(str, subString, subString.size(), str.size());
	return 0;
}
