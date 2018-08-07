#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
#define ll long long int
using namespace std;

void printAnagrams(string words[], int n) {

    int prime[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
    map<ll, vector<string> > hash;
    for(int i = 0; i < n; i++) {
        ll s = 1;
        for(int j = 0; j < words[i].length(); j++) {
            s *= prime[words[i][j] - 'a'];
        }
        if(hash.find(s) != hash.end()) {
            hash.find(s)->second.push_back(words[i]);
            hash.insert(pair<ll,vector<string> >(s, hash.find(s)->second));
        } else {
            vector<string> v;
            v.push_back(words[i]);
            hash.insert(pair<ll,vector<string> >(s, v));
        }
    }
    for(auto it = hash.begin(); it!=hash.end(); it++) {

        for(int j =0; j < (*it).second.size(); j++) {
            cout<<(*it).second[j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[])
{

    string word[] = { "eat", "pots", "onset", "stone", "rail", "risen", "caret", "resin", "react", "siren", "sitar", "stair", "liar", "stop", "trace", "notes", "tea", "lair" };
    printAnagrams(word, 18);
    return 0;
}
