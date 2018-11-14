#include <bits/stdc++.h>
using namespace std;

// Square Root Decomposition 
// Range Sum Query

int query(int *blocks,int *arr,int l,int r,int rn){
    
    int ans = 0;
    
    //Left Part 
    while(l<r && l!=0 && l%rn!=0){
        ans += arr[l];
        l++;
    }
    
    //Middle Part
    while(l + rn<=r){
        int block_id = l/rn;
        ans += blocks[block_id];
        l += rn;
    }
    
    //Right Part 
    while(l<=r){
        ans += arr[l];
        l++;
    }
    return ans;
    
}

void update(int *blocks,int *arr,int i,int val,int rn){
    
    int block_id = i/rn;
    blocks[block_id] += (val - arr[i]);
    arr[i] = val;
}

int main() {
    
    int a[] = {1,3,5,2,7,6,3,1,4,8};
    int n = sizeof(a)/sizeof(int);
    
    int rn = sqrt(n);
    int *blocks = new int[rn+1]{0};
    
    // Build a Blocks Array
    int block_id = -1;
    for(int i=0;i<n;i++){
        
        if(i%rn==0){
            block_id++;
        }
        blocks[block_id] += a[i];
    }
    
    // Queries
    int l,r;
    cin>>l>>r;
    update(blocks,a,2,15,rn);
    cout<<query(blocks,a,l,r,rn);


}
