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
    Demo obj(1);
    std::shared_ptr<Demo> ptr1 = std::make_shared<Demo>(obj);
    std::shared_ptr<Demo> ptr2(new Demo(10));
    std::shared_ptr<Demo> ptr3 = ptr1;
    {
        std::shared_ptr<Demo> ptr4 = ptr1;
    }
    
    std::cout<<ptr1.use_count()<<"\n";
    return 0;
}
