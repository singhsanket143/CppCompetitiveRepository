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
    std::shared_ptr<int> p1(new int(10));
    std::shared_ptr<int> p2 = std::make_shared<int>(10);
    std::shared_ptr<int> p3 = p1;
    std::shared_ptr<int> p4 = p1;
    *p4 = 99;
    std::cout<<*p1<<" "<<*p3<<" "<<*p4<<"\n";

    std::shared_ptr<temp> sp;
    {
        std::cout<<"Inside block\n";
        std::shared_ptr<temp> sp1(new temp());
        sp = sp1;
        std::cout<<sp1<<"\n";
        std::cout<<sp1.use_count()<<"\n";
        std::cout<<sp.use_count()<<"\n";
    }
    std::cout<<"Ouitside block\n";
    std::cout<<sp.use_count()<<"\n";
    std::cout<<sp<<"\n";
    return 0;
}
