#include<iostream>
#include<memory>

struct temp {
    int x;
    temp() {
        std::cout<<"constructor called\n";
    }
    ~temp() {
        std::cout<<"Destructor called\n";
    }
};

int main(int argc, char const *argv[])
{
    // std::unique_ptr<type> name(new type());
    // std::unique_ptr<type> name = std::make_unique<type>(new type());
    std::cout<<"Start\n";
    {
        std::unique_ptr<int> u1(new int(1234));
        std::cout<<*u1<<"\n";
        std::unique_ptr<temp> u2(new temp()); // init in a heap
        temp *ptr = new temp(); // init in a heap
        delete ptr;
        int x;
    }
    std::unique_ptr<int> p1(new int(100));
    std::unique_ptr<temp> p2(new temp());
    p2.reset();
    // std::unique_ptr<int> p2 = p1; throws error becase unique pointer cant share memory space



    
    std::cout<<"finish\n";
    
    return 0;
}
