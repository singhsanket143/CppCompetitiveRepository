#include<iostream>

int main(int argc, char const *argv[])
{
    int* p = (int*)std::malloc(5);
    *p = 10;
    std::cout<<*p<<"\n";

    int* arr= (int*)std::calloc(3, 4);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::cout<<arr[1]<<" "<<*(arr+2)<<"\n";

    size_t s = 10;
    std::cout<<s<<"\n";

    std::free(p);
    return 0;
}
