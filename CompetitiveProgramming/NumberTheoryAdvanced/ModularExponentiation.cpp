#include<iostream>
using namespace std;


int modRecursive(int a,int b,int c){
	if(b == 0){
		return 1;
	}

	if(b%2 ==0){

		//Even
		return modRecursive((a*a)%c,b/2,c);
	}else{
		// Odd
		return ((a%c)*(modRecursive((a*a)%c,b/2,c)))%c;
	}

}
int main(){
	
	cout<<modRecursive(2,6,5)<<endl;	

	return 0;
}