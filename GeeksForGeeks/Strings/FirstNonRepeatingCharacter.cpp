#include "iostream"
#include "limits"
#include "stdio"
using namespace std;

char firstNonRepeatingCharacter(string str) {
    pair<int, int> arr[256];
    for(int i=0;i<256;i++) {
        arr[i].second = 0;
    }
    for(int i = 0; i < str.length(); i++) {
        if(arr[str[i]].second == 0) {
            arr[str[i]].first = i;
            arr[str[i]].second = 1;
        } else {
            arr[str[i]].second++;
        }
    }
    int bestCandidate = INT_MAX;
    for(int i=0;i<256;i++) {
        if(arr[i].second == 1) {
            bestCandidate = min(bestCandidate, arr[i].first);
        }
    }
    return bestCandidate;
}

int main(int argc, char* argv[])
{
    string str = "geeksforgeeks";
    int index = firstNonRepeatingCharacter(str);
    if (index == INT_MAX)
        printf("Either all characters are "
              "repeating or string is empty");
    else
        printf("First non-repeating character"
               " is %c", str[index]);

    return 0;
}
