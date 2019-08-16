#include<iostream>
using namespace std;

//Binary Search 
//--> Sorted Array element mei search element
int binary_search(int a[],int key,int n){
	//write the algorithm

	int s  = 0;
	int e = n-1;

	while(s<=e){
		int mid = (s+e)/2;

		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]<key){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return -1;
}


int squareRoot(int n){

	int s = 0;
	int e = n;

	int ans = -1;

	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid==n){
			return mid;
		}
		else if(mid*mid<n){
			s = mid + 1;
			ans = mid;
		}
		else{
			e = mid - 1;
		}
		return ans;
	}


}

int main(){


	int a[] = {-1,2,5,7,10,12,15,20};
	int n = sizeof(a)/sizeof(int);
	int key;
	cin>>key;
	//Binary Search
	//cout<<binary_search(a,key,n)<<endl;
	cout<<squareRoot(key);
	

	return 0;
}
