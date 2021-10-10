#include<iostream>
#include<limits.h>

struct Stack {
    int n; // size of the array
    int *arr;
    int last; // i

    Stack(int sz) {
        n = sz;
        arr = new int[n];
        last = -1;
    }

    void push(int el) {
        if(last == n-1) {
            std::cout<<"Stack is full\n";
            return;
        }
        last++;
        arr[last] = el; 
    }

    void pop() {
        if(last < 0) {
            std::cout<<"Stack is empty\n";
            return;
        }
        last--;
    }

    int top() {
        if(last < 0) {
            std::cout<<"Stack is empty\n";
            return INT_MIN;
        }
        return arr[last];
    }
    bool isEmpty() {
        return last < 0;
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.push(50);

    while(not s.isEmpty()) {
        std::cout<<s.top()<<"\n";
        s.pop();
    }
    return 0;
}
