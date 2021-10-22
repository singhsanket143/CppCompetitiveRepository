#include<iostream>

int main(int argc, char const *argv[])
{
    // new // delete
 
    int* i = new int(8);
    std::cout<<*i<<"\n";
    int* arr = new int[10];
    arr[0] = 9;

    delete i;
    delete [] arr;
    return 0;
}
