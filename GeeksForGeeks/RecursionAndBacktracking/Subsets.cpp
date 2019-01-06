#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<vector<int>> powerset, vector<int> subset){
		
        //powerset.push_back(subset);

        for(int i = start; i < nums.size(); i++){  
            // recording all subsets that include nums[i]
            subset.push_back(nums[i]); 
	        powerset.push_back(subset); 
	  
	        // move onto the next element. 
	        backtrack(nums, i+1, powerset, subset); 
	  
	        // exclude the A[i] from subset and triggers 
	        // backtracking. 
	        subset.pop_back(); 
        }
}
vector<vector<int>> subsets(vector<int>& nums) {  
		vector<vector<int>> powerset; 
		vector<int> subset;  
		powerset.push_back(subset);   
        backtrack(nums, 0, powerset, subset);
        for (int i = 0; i < powerset.size(); i++) { 
        for (int j = 0; j < powerset[i].size(); j++) 
            cout << powerset[i][j] << " "; 
        	cout << endl; 
    
		}
        return powerset;
}


int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++) {
		cin>>x;
		nums.push_back(x);
	}
	vector<vector<int>> powerset = subsets(nums);
	
	return 0;
}
