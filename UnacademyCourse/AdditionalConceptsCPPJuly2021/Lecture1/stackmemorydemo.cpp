#include<bits/stdc++.h>

struct temp {
    int x, y;
    temp() {
        std::cout<<"Constructor called"<<"\n";
    }
    ~temp() {
        std::cout<<"Destructor Called"<<"\n";
    }
};

void fun() {
    temp t; // This is allocated in stack memory
    t.x=10;
}

void gun() {
    temp *t = new temp; // allocation in heap
    delete t; // manual deletion from heap
}

int main(int argc, char const *argv[])
{
    fun();
    gun();
    int x = 10; // This is allocated in stack memory
    std::cout<<x<<"\n";

    int *ptr = new int;
    std::cout<<ptr<<"\n";
    std::cout<<*ptr<<"\n";
    *ptr = 10;
    delete ptr;
    std::cout<<*ptr<<"\n";

    {
        temp t1;
    }
    std::cout<<"Out of scope\n";


    int *arr = new int[2];
    arr[0] = 10;
    arr[1] = 20;
    std::cout<<arr[0]<<"\n";
    delete [] arr;

    temp* trr = new temp[2];
    // temp trr[2];
    delete [] trr;

    int *a = new int[5](); // initialised by all zeroes


    // 2d array demo
    int **grid = new int*[5];
    for(int i = 0; i < 5; i++) {
        grid[i] = new int[4];
    }

    std::cout<<grid<<"\n";
    std::cout<<grid[0]<<"\n";
    std::cout<<&grid[0]<<"\n";

    temp** sg = new temp*[2];
    for(int i = 0; i < 2; i++) {
        sg[i] = new temp[3];
    }
    for(int i = 0; i < 2; i++) {
        delete [] sg[i];
    }
    delete [] sg;

    std::cout<<"--------------\n";
    int *y = (int*) malloc(5);
    free(y);
    
    int *t = new int;
    free(t);

    temp *t1 = new temp[10];
    // delete [] t1;
    for(int i = 9; i >= 0; i--) {
        free(t1+i);
    }
    // free(t1);
    return 0;
}
