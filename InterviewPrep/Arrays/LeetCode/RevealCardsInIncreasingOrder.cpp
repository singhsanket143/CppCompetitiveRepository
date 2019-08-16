#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<queue>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a deck of cards
 // It should return the answer deck
 vector<int> deckRevealedIncreasing(vector<int>& deck) {
 //Write your code here	 	 
 int result[deck.size()];
        sort(deck.begin(), deck.end());
        queue<int> qu;
        for(int i=0;i<deck.size();i++) {
            qu.push(i);
        }
        for(int card: deck) {
            int x = qu.front();
            qu.pop();
            result[x] = card;
            if(!qu.empty()) {
                int y = qu.front();
                qu.pop();
                qu.push(y);
            }
        }
        return vector<int> (result, result+deck.size());
 }
 
 //Don't make any changes here.
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> Input(n);
     for(int i=0;i<n;i++){
         cin>>Input[i];
     }
     vector<int> ans = deckRevealedIncreasing(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }
 
 }