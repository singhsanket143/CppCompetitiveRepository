#include<iostream>
#include<stack>

int main(int argc, char const *argv[])
{
    /* code */
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.push(50);

    while(not s.empty()) {
        std::cout<<s.top()<<"\n";
        s.pop();
    }

    return 0;
}
