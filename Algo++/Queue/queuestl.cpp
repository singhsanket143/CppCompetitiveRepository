#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
	queue<int> q;
	for(int i=0;i<10;i++) {
		q.push(i);
	}
	while(!q.empty()) {
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
