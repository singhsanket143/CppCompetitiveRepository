#include<bits/stdc++.h>
using namespace std;
struct expense{
    string person1;
    string person2;
    int amount;
​
    void set(string p1, string p2, int val){
        person1 = p1;
        person2 = p2;
        amount = val;
    }
};
vector<expense> splitwise(vector<expense> transactions){
    map<string, int> net_balance;
    for(auto e: transactions){
        net_balance[e.person1]+=e.amount;
        net_balance[e.person2]-=e.amount;
    }
​
    priority_queue<pair<int,string>> positive, negative;
    for(auto p:net_balance){
        if(p.second > 0){
            positive.push(make_pair(p.second, p.first));
        }else if(p.second < 0){
            negative.push(make_pair(abs(p.second), p.first));
        }
    }
    vector<expense> result;
​
    while(!positive.empty()){
        auto p1 = positive.top();
        auto p2 = negative.top();
        positive.pop();
        negative.pop();
        expense exp;
        exp.set(p2.second, p1.second, min(p1.first, p2.first));
        result.push_back(exp);
        if(p1.first > p2.first){
            positive.push(make_pair(p1.first-p2.first, p1.second));
        }else if(p1.first < p2.first){
            negative.push(make_pair(p2.first-p1.first, p2.second));
        }
    }
​
    return result;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
​
    /*Testing the function
    Input:
    7
    A B 10
    B C 5
    B D 5
    C A 10
    E F 8
    F G 9
    H F 1
​
    Expected Output:
    G E 8
    D C 5
    G H 1
    */
    vector<expense> input;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string p1, p2;
        int val;
        cin>>p1>>p2>>val;
        expense exp;
        exp.set(p1, p2, val);
        input.push_back(exp);
    }
    vector<expense> output = splitwise(input);
    for(auto e:output){
        cout<<e.person1 <<" "<<e.person2 <<" "<<e.amount<<endl;
    }
    return 0;
}p