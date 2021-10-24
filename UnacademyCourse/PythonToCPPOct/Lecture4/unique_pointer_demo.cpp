#include<iostream>
#include<memory>

class Demo {
public:
    int x;
    Demo() {
        std::cout<<"Default Constructor called\n";
    }
    Demo(int v) {
        std::cout<<"Parametrized Constructor called\n";
        x = v;
    }

    ~Demo() {
        std::cout<<"Destructor called\n";
    }
};

int main(int argc, char const *argv[])
{   
    Demo obj(250);
    std::unique_ptr<Demo> ptr1 = std::make_unique<Demo>(obj);
    std::unique_ptr<Demo> ptr2(new Demo(500));

    std::cout<<ptr1->x<<" "<<ptr2->x<<"\n";
    ptr1->x = 99;
    std::unique_ptr<Demo> ptr3 = std::make_unique<Demo>(obj);
     std::cout<<ptr3->x<<"\n";

    ptr1.reset();
    ptr2.reset();

    return 0;
}
