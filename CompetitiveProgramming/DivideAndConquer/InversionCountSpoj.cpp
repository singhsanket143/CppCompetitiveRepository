#include<iostream>
#define ll long long int
using namespace std;


long long int merge(ll A[],ll left,ll mid,ll right){

	ll i=left,j=mid,k=0;

	ll temp[right-left+1];
	long long int count = 0;
	while(i<mid && j<=right){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
		}else{
			temp[k++] = A[j++];
			count += mid - i;
		}
	}
	while(i<mid){
		temp[k++] = A[i++];
	}
	while(j<=right){
		temp[k++] = A[j++];
	}

	for(ll i=left,k=0;i<=right;i++,k++){
		A[i] = temp[k];
	}
	return count;
}
long long int merge_sort(ll A[],ll left,ll right){

	long long int count = 0;
	if(right > left){
		ll mid = (left + right)/2;

		long long int countLeft = merge_sort(A,left,mid);
		long long int countRight = merge_sort(A,mid+1,right);
		long long int myCount = merge(A,left,mid+1,right);

		return myCount + countLeft + countRight;
	}
	return count;

}
long long int solve(ll A[], ll n)
{
	long long int ans = merge_sort(A,0,n-1);
	return ans;
}

int main(){
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++) {
			cin>>arr[i];
		}
		cout << solve(arr,n) <<endl;
	}
	
	return 0;
}