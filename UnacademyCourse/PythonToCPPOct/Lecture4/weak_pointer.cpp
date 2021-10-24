#include<iostream>
#include<memory>
class B;
class A {
    public:
    int a;
    std::shared_ptr<B> ptr;
    A(int v = 20) {
        a = v;
    }
    ~A() {
        std::cout<<"Destructor called\n";
    }
};
class B {
    public:
    int a;
    std::weak_ptr<A> ptr;
    B(int v = 20) {
        a = v;
    }
    ~B() {
        std::cout<<"Destructor called\n";
    }
};

int main(int argc, char const *argv[])
{
    std::shared_ptr<A> ptr_a = std::make_shared<A>(750);
    std::shared_ptr<B> ptr_b = std::make_shared<B>(750);
    ptr_a->ptr = ptr_b;
    ptr_b->ptr = ptr_a;

    std::shared_ptr<A> p1 = std::make_shared<A>(11);
    std::weak_ptr<A> w = p1;
    std::cout<<p1.use_count()<<"\n";
    p1.reset();
    std::cout<<w.expired()<<"\n";
    return 0;
}
