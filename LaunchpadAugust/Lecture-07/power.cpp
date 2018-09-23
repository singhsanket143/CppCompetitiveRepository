#include<iostream>
using namespace std;

// Power- a,b  Return a power b
int power(int a,int n){
	if(n==0){
		return 1;
	}
	return power(a,n-1)*a;
}

int powerfast(int a,int n){
	if(n==0){
		return 1;
	}
	int smallPower = powerfast(a,n/2);
	smallPower = smallPower*smallPower;
	//Even
	if(n%2==0){
		return smallPower;
	}
	//Odd
	return a*smallPower;
}

int main(){
	int a,n;
	cin>>a>>n;

	cout<< power(a,n)<<endl;
	cout<< powerfast(a,n)<<endl;
}