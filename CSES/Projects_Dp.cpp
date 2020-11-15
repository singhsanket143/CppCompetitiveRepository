#include <bits/stdc++.h>
#define ll long long int
using namespace std; 

struct Job 
{ 
    ll start, finish, profit; 
}; 
  
bool myfunction(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
int binarySearch(Job jobs[], ll index) 
{ 
    ll lo = 0, hi = index - 1; 
  
    while (lo <= hi) 
    { 
        ll mid = (lo+hi) / 2; 
        if (jobs[mid].finish < jobs[index].start) 
        { 
            if (jobs[mid + 1].finish < jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 
  
ll findMaxProfit(Job arr[], ll n) 
{ 
    sort(arr, arr+n, myfunction); 
  
    ll *table = new ll[n]; 
    table[0] = arr[0].profit; 
  
    for (ll i=1; i<n; i++) 
    { 
        ll inclProf = arr[i].profit; 
        ll l = binarySearch(arr, i); 
        if (l != -1) 
            inclProf += table[l]; 
  
        table[i] = max(inclProf, table[i-1]); 
    } 
  
    ll result = table[n-1]; 
    delete[] table; 
  
    return result; 
} 
  
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main() 
{ 
    file_i_o();
    ll n;
    cin>>n;
    struct Job arr[n];
    for(int i=0;i<n;i++) {
        ll a,b,c;
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
        // cout<<arr[i].start<<" "<<arr[i].finish<<" "<<arr[i].profit<<endl;;
    }
    cout << findMaxProfit(arr, n); 
    return 0; 
} 