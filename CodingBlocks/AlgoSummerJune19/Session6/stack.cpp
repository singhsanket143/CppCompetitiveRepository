#include <iostream>
using namespace std;

class Stack{

	int* arr;
	int top;

public:
	int default_size = 5;
	Stack(int s = 5){
		default_size = s;
		top = 0;
		arr = new int[default_size];
	}
	bool isFull(){
		return top == default_size;
	}

	void push(int data){
		if(isFull()){
			cout<<"stack is full"<<endl;
			return;
		}
		arr[top] = data;
		top++;
	}

	bool isempty(){
		return top==0;
	}
	void pop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return;
		}
		top--;
	}
	int atTop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return -1;
		}
		return arr[top-1];
	}

};

int main(int argc, char const *argv[])
{
	Stack st(4);

	cout<<st.isempty()<<endl;
	st.push(100);
	st.push(200);
	st.push(300);
	st.push(400);
	st.push(500);

	cout<<st.atTop()<<endl;
	st.pop();
	cout<<st.atTop()<<endl;
	st.pop();
	cout<<st.atTop()<<endl;
	st.pop();
	cout<<st.atTop()<<endl;
	st.pop();
	cout<<st.atTop()<<endl;
	st.pop();


	return 0;
}


