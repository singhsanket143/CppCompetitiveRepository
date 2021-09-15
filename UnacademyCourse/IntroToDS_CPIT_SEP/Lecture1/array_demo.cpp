#include<iostream>

int a2[100]; // global array

void fun() {
    int arr[10]; // array in stack
    std::cout<<arr<<"\n";
}

int main(int argc, char const *argv[])
{
    fun();

    int *a1 = new int[7]; // array in heap

    // int a2[10] = {1,2,3};
    int *a2 = new int[10]();
    for(int i = 0; i < 10; i++) {
        std::cout<<a2[i]<<"\n";
    }

    int a3[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++) {
        std::cout<<a3[i]<<"\n";
    }
    return 0;
}
