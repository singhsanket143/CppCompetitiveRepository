#include "iostream"
#include "unordered_map"
#include "priority_queue"
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char> > qu;
        unordered_map<char, int> mp;
        for(int i = 0; i < S.size(); i++) {
            mp[S[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int x = (*it).second;
            char y = (*it).first;
            if(x > (S.size() + 1)/2) return "";
            qu.push(make_pair(x, y));
        }
        string ans = "";
        while(qu.size() >= 2) {
            pair<int, char> p1 = qu.top();
            qu.pop();
            pair<int, char> p2 = qu.top();
            qu.pop();
            ans = ans+p1.second;
            ans = ans+p2.second;
            p1.first-=1;
            p2.first-=1;
            if(p1.first > 0) qu.push(p1);
            if(p2.first > 0) qu.push(p2);
        }
        if(qu.size() > 0) {
            ans+=qu.top().second;
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}