// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
}
struct temp {

};
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    const int x = 10; // const makes it unmodifiable
    // x = 20; -> we can't do this

    // const int y; can't do this as we need to init a const variable always

    const int ENV = 123;
    int NORMAL = 456;
    int *ptr = new int;
    ptr = &NORMAL;
    // ptr = &ENV; we can't do this
    const int *ptr1 = &ENV;
    ptr = (int *)&ENV;
    *ptr = 8;
    std::cout<<*ptr<<" "<<ENV<<"\n";
    std::cout<<ptr<<" "<<&ENV<<"\n";


    int const *p = new int;
    int y = 10;
    *p = 2;
    p = &y;
    y = 6;
    // *p = 2;
    p = (int *)&ENV;
    const int h = 99;
    int* const p1 = new int;
    *p1 = 2;
    int z = 9;
    p1 = &z;

    const int* const p2 = new const int(3);
    p2 = &y;
    *p2 = 100;

    int x1;
    std::cin>>x1;
    const int y = x;

    
    const temp* const t = new const temp;
    return 0;
}