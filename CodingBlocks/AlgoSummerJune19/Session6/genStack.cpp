#include <iostream>
using namespace std;

template<typename T>
class Stack{

	T* arr;
	int top;

public:
	int default_size = 5;
	Stack(int s = 5){
		default_size = s;
		top = 0;
		arr = new T[default_size];
	}
	bool isFull(){
		return top == default_size;
	}

	void push(T data){
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
	T atTop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return NULL;
		}
		
			return arr[top-1];
		
		
	}

};

int main(int argc, char const *argv[])
{
	Stack<string> st(4);

	cout<<st.isempty()<<endl;
	st.push("abc");
	st.push("def");
	st.push("ghi");
	st.push("jkl");
	st.push("mno");

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


