#include "iostream"
using namespace std;

int main()
{
	for(int j = 3; j < 5; j++) {
		for(int i = 0; i<10; i++) {
			if(i == 5) continue;
			if(i == 7) break;
			cout<<i<<endl;
		}
	}
	
	return 0;
}