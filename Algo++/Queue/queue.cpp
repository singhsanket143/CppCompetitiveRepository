#include <iostream>
using namespace std;

class Queue {
	int *arr;
	int ms; // max size
	int cs; // current size
	int front;
	int rear;
public:
	Queue(int default_size = 4) {
		front = 0;
		rear = default_size-1;
		ms = default_size;
		arr = new int[ms];
		cs = 0;
	}
	bool isFull() {
		return cs==ms;
	}
	bool isEmpty() {
		return cs == 0;
	}
	void enqueue(int data) {
		if(!isFull()) {
			rear = (rear+1)%ms;
			arr[rear] = data;
			cs++;
		}
	}
	void dequeue() {
		if(!isEmpty()) {
			front = (front+1)%ms;
			cs--;
		}
	}
	int getFront() {
		return arr[front];
	}
};
int main(int argc, char const *argv[])
{
	Queue q;
	for(int i=1;i<=6;i++) {
		q.enqueue(i);
	}
	q.dequeue();
	q.enqueue(8);
	while(!q.isEmpty()) {
		cout<<q.getFront()<<endl;
		q.dequeue();
	}
	return 0;
}
