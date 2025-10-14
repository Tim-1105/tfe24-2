#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value) //Funktionsdeklaration
    {
        value = 99;
        fmt::print("Inside changeValueByParameter, value is: {}\n", value);
    }
    
void changeValueByReference(int& ref) //Funktionsdeklaration
    {
        ref = 77;
        fmt::print("Inside changeValueByReference, value is: {}\n", ref);
    }

auto main(int argc, char **argv) -> int
{

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tfe24::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */

    //Teil 1: Grundlagen Referenzen:
    int x = 10;
    int& r = x; //Referenz r auf x
    fmt::print("Werte von x und r: x = {}, r = {}\n", x, r);
    r = 42; //Ändern von x über referenz r
    fmt::print("Werte von x und r nach Änderung über r: x = {}, r = {}\n", x, r);


    //Teil 2: Funktionen mit Referenzen:
    int y = 5;
    fmt::print("Before changeValueByParameter, y is: {}\n", y);
    changeValueByParameter(y);
    fmt::print("After changeValueByParameter, y is: {}\n", y);

    fmt::print("Before changeValueByReference, y is: {}\n", y);
    changeValueByReference(y);
    fmt::print("After changeValueByReference, y is: {}\n", y);

    return 0; /* exit gracefully*/
}
