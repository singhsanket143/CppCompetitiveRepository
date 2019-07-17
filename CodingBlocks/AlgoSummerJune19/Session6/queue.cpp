#include <iostream>
using namespace std;

template<typename T>
class Queue{
	T* arr;
	int front;
	int rear;
	int cs;

public:
	int default_size;
	Queue(int size=5){
		cs = 0;
		default_size = size;
		front = 0;
		rear = -1;
		arr = new T[default_size];
	}
	bool isfull(){
		return cs ==default_size;
	}
	bool isempty(){
		return cs == 0;
	}
	void push(T data){
		if(isfull()){
			cout<<"queue is full"<<endl;
			return;
		}
		rear = (rear+1)%default_size;
		arr[rear] = data;
		cs++;
	}

	void pop(){
		if(isempty()){
			cout<< "queue is empty"<<endl;
			return;
		}
		front = (front+1) % default_size;
		cs--;
	}
	T atFront(){
		if(isempty()){
			cout<< "queue is empty"<<endl;
			return NULL;
		}
		return arr[front];
	}

};
int main(int argc, char const *argv[])
{
	Queue<string> st(4);

	cout<<st.isempty()<<endl;
	st.push("abc");
	st.push("def");
	st.push("ghi");
	st.push("jkl");
	st.push("mno");

	cout<<st.atFront()<<endl;
	st.pop();
	cout<<st.atFront()<<endl;
	st.pop();
	cout<<st.atFront()<<endl;
	st.pop();
	cout<<st.atFront()<<endl;
	st.pop();
	cout<<st.atFront()<<endl;
	st.pop();
	return 0;
}







