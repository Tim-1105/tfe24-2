#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

//Funktionen zu Teil 3

void changeValueByParameter(int value)
    {
        value = 99;
        fmt::print("Inside changeValueByParameter, value is: {}\n", value);
    }

void changeValueByPointer(int* ptr)
    {
        *ptr = 77;
        fmt::print("Inside changeValueByPointer, value is: {}\n", *ptr);
    }


auto main(int argc, char **argv) -> int
{

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello World, {}!\n", tfe24::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */

    //Teil 1: Zeiger-Grundlagen

    int x = 10;
    int* p = &x;
    fmt::print("The value of x is: {}\n", x);
    fmt::print("The address of x is: {}\n", fmt::ptr(&x));
    
    fmt::print("The value of p is: {}\n", *p);
    fmt::print("The address of p is: {}\n", fmt::ptr(p));

    *p = 42;
    fmt::print("The new value of x is: {}\n", x);
    fmt::print("The new value of p is: {}\n", *p);

    //Teil 2:Dynamische Speicherverwaltung

    double* pi = new double(3.1415);
    fmt::print("The value of pi is: {}\n", *pi);
    fmt::print("The address of pi is: {}\n", fmt::ptr(pi));
    delete pi;

    //Teil 3: Funktionen mit Zeigern

    int y = 5;
    fmt::print("Before changeValueByParameter, y is: {}\n", y);
    changeValueByParameter(y);
    fmt::print("After changeValueByParameter, y is: {}\n", y);

    fmt::print("Before changeValueByPointer, y is: {}\n", y);
    changeValueByPointer(&y);
    fmt::print("After changeValueByPointer, y is: {}\n", y);

    
    return 0; /* exit gracefully*/
}