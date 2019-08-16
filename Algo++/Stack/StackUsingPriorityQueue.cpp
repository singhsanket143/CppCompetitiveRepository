#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

class Stack {
	int cnt;
	priority_queue<pair<int, int> >pq;
public:
	Stack() {
		this->cnt = 0;
	}
	void push(int data) {
		cnt++;
		pq.push(pi(cnt, data));
	}
	void pop() {
		if(pq.empty()) {
			cout<<"Nothing to pop";
		} else {
			this->cnt--;
			pq.pop();
		}
	}
	int top() {
		pi temp = pq.top();
		return temp.second;
	}
	bool isEmpty() {
		return pq.empty();
	}
};

int main(int argc, char const *argv[])
{
	Stack *s = new Stack();
	s->push(1);
	s->push(10);
	s->push(1000);
	while(!s->isEmpty()) {
		cout<<s->top()<<" ";
		s->pop();
	}
	return 0;
}
