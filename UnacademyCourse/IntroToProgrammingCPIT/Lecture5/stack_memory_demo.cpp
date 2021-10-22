#include<iostream>
#include<queue>
void gun() {
    std::cout<<"gun\n";
    int x = 10;
    return;
}

void fun() {
    int x = 10;
    int arr[5];
    std::cout<<"fun\n";
    gun();
}

int main() {
    fun();
    std::queue<int> qu;
    qu.push(1);
    qu.pop();
    return 0;
}