#include<iostream>
#include<stdlib.h>


int* fun() {
    int *x = new int(78);
    std::cout<<"x = "<<x<<" "<<*x<<"\n";
    return x;
}

int main() {

    int* ptr = (int*) malloc(4);
    *ptr = 10;
    std::cout<<*ptr<<"\n";

    int* x = new int(99);
    std::cout<<*x<<"\n";
    *x = 10;
    std::cout<<x<<" "<<*x<<"\n";


    int* arr = new int[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    for(int i = 0; i < 10; i++) {
        std::cout<<arr[i]<<" ";
    }

    delete x; // single bucket
    delete [] arr; // 1d array
    std::cout<<"\n";

    int* p = fun();
    std::cout<<p<<" "<<*p<<"\n";
    return 0;
}