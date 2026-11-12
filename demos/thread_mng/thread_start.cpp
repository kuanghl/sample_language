#include <iostream>
#include <thread>
#include <functional>

void printf_hello(uint16_t val)
{
   std::cout << "Hello World! At a thread." << val << std::endl;
}

class background_task {
public:
    // alloc
    background_task() 
    {
        std::cout << "background_task()" << std::endl;
    }

    // free
    ~background_task() 
    {
        std::cout << "~background_task()" << std::endl;
    }

    void operator()() const 
    {
        do_something();
        do_something_else();
    }

private: 
    void do_something() const 
    {
        std::cout << "Doing something..." << std::endl;
    }

    void do_something_else() const 
    {
        std::cout << "Doing something else..." << std::endl;
    }
};

int main(int argc, char *argv[]) {

#if 0 // std
    background_task bt;

    // std::bind call object
    auto thread_func = std::bind(&background_task::operator(), &bt);

    // thread run
    std::thread thread_b(thread_func);
    thread_b.join();

#else //lambda
    background_task bt;

    std::thread thread_b([&bt](){ 
        bt(); 
    });

    thread_b.join();
#endif

    return 0;
}