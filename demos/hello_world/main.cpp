#include <iostream>
#include <thread>

void printf_hello(void)
{
   std::cout << "Hello World! At a thread." << std::endl;
}

int main(int argc, char *argv[])
{
   std::cout << "Hello CMake!, Hello World!" << std::endl;

   std::thread thread_a(printf_hello); 
   thread_a.join(); 

   return 0;
}

