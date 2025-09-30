#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

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
    

    return 0; /* exit gracefully*/
}
