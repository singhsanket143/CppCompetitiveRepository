#include<iostream>
using namespace std;

#define ll long long int

bool isValidConfig(ll books[],ll n,ll k,ll ans){
        
    int students=1;
    ll current_pages = 0;
    
    for(int i=0;i<n;i++){
        
        if(current_pages+books[i]>ans){
            current_pages = books[i];
            students++;
            if(students>k){
                return false;
            }
            
        }
        else{
            current_pages += books[i];
            
        }
    }
    return true;
}

ll binarySearchBooks(ll books[],ll n,ll k){
    
    ll total_pages = 0;
    ll s=0,e=0;
    for(int i=0;i<n;i++){
        total_pages += books[i];
    }
    s = books[n-1];
    
    e = total_pages;
    int finalAns = s;
    
    while(s<=e){
        ll mid = (s+e)/2;
        
        if(isValidConfig(books,n,k,mid)){
            ///true
            finalAns = mid;
            e = mid-1;
            
        }
        else{
            //FALSE
            s = mid + 1;
        }
        
        
    }
    
    return finalAns;
    
}

int main(){
    
    ll n;
    ll k;
    
    cin>>n>>k;
    
    ll books[100005];
    
    for(int i=0;i<n;i++){
        cin>>books[i];
    }
    cout<<binarySearchBooks(books,n,k)<<endl; 
}

