#include "iostream"
using namespace std;

bool compare(int arr1[], int arr2[]) {
    for(int i = 0; i < 256; i++) {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}

void search(string txt, string pat) {
    int m = pat.length(), n = txt.length();
    int countP[256] = {0};
    int countT[256] = {0};
    for(int i = 0; i < m; i++) {
        countP[pat[i]]++;
        countT[txt[i]]++;
    }
    for(int i = m; i < n; i++) {
        if(compare(countP, countT)) {
            cout << "Find at index " << (i-m) << endl;
        }
        countT[txt[i]]++;
        countT[txt[i-m]]--;
    }
    if(compare(countP, countT)) {
        cout << "Find at index " << (n-m) << endl;
    }
}

int main(int argc, char* argv[])
{

    string txt = "BACDGABCDA";
    string pat = "ABCD";
    search(txt, pat);
    return 0;
}
