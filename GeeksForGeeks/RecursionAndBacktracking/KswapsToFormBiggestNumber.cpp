#include <iostream>
using namespace std;
int Kswap(int num, int k)
{
    
    
    string arr = to_string(num);
    int i, j, min_idx;
    int n =arr.length();
    // One by one move boundary of unsorted subarray
    for (i = 0; i < k; i++)
    {
        // Find the max element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] > arr[min_idx])
            min_idx = j;
 
        // Swap the found max element with the first element
        swap(arr[min_idx], arr[i]);
    }
    
    
    int ans = stoi(arr);
    return ans;
}
 

int main() {
	// your code goes here
    int a, b;
    cin>>a>>b;
	cout<<Kswap(a,b)<<endl;
	
	
	return 0;
}