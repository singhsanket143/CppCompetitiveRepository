#include<iostream>
#include<memory>
class Demo {
    public:
    int x;
    int y;
    Demo() {
        std::cout<<"Constructor Called\n";
    }
    void fun() {
        std::cout<<"Have fun!!\n";
    }
    ~Demo() {
        std::cout<<"Destructor called\n";
    }
};

int main(int argc, char const *argv[])
{
    // new // delete
    // Demo d;
    //Demo* d = new Demo();

    {
        // Demo* d = new Demo();
        std::unique_ptr<Demo> ptr(new Demo());
    }
    std::cout<<"Out oif scope\n";
    return 0;
}


// _start()