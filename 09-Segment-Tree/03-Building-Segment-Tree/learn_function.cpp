#include <iostream>
#include <functional>

typedef int (*func)();

int print1()
{
    printf("hello, print1 \n");
    return 0;
}

int print2()
{
    printf("hello, print2 \n");
    return 0;
}


struct A {
    void operator()() {
        std::cout << "This is A Object" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    func fp = print1;
    fp();

    fp = print2;
    fp();
    std::function<void()> func2;

    func2 = &print1;
    func2();
    func2 = &print2;
    func2();

     A a;
    func2 = a;
    func2();


    return 0;
}