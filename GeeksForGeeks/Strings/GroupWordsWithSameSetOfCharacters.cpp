#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

string getKey(string str) {
    bool visited[26] = {false};
    for(int i=0;i<str.length();i++) {
        visited[str[i]-'a'] = true;
    }
    string key="";
    for(int i=0;i<26;i++) {
        if(visited[i]){
            key = key + char('a' + i);
        }
    }
    return key;

}

void wordsWithSameCharSet(string words[], int n) {
    unordered_map <string, vector <int> > hash;
    for(int i=0;i<n;i++) {
        string key = getKey(words[i]);
        hash[key].push_back(i);
    }
    for(auto it = hash.begin(); it!=hash.end(); it++) {
        for(auto v=(*it).second.begin(); v!=(*it).second.end(); v++) {
            cout<<words[*v]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[])
{
    string words[] = { "may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act", "tab",
                 "bat", "flow", "wolf", "lambs", "amy", "yam",
                 "balms", "looped", "poodle"};
    int n = sizeof(words)/sizeof(words[0]);
    wordsWithSameCharSet(words, n);
    return 0;
}
