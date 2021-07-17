#include<iostream>
#include<memory>

struct B;

struct A {
    int a;
    std::shared_ptr<B> ptr;
    A(int v = 20) {
        a = v;
        std::cout<<"Constructor of A\n";
    }
    ~A() {
        std::cout<<"Desstructor of A\n";
    }
};

struct B {
    int b;
    std::weak_ptr<A> ptr;
    B(int v = 20) {
        b = v;
        std::cout<<"Constructor of B\n";
    }
    ~B() {
        std::cout<<"Desstructor of B\n";
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    std::shared_ptr<A> pa = std::make_shared<A>(75);
    std::shared_ptr<B> pb = std::make_shared<B>(76);

    pa->ptr = pb;
    pb->ptr = pa;


    std::shared_ptr<int> ptr = std::make_shared<int>(99);
    std::shared_ptr<int> ptr1 = ptr;
    std::weak_ptr<int> watcher = ptr;
    std::cout<<ptr<<"\n";
    std::cout<<watcher.expired()<<"\n";
    ptr.reset();
    std::cout<<"Ref count "<<ptr.use_count()<<"\n";
    std::cout<<watcher.expired()<<"\n";
    std::cout<<ptr<<" "<<ptr1<<"\n";
    ptr1.reset();
    std::cout<<watcher.expired()<<"\n";
    std::cout<<ptr.use_count()<<"\n";
    return 0;
}
