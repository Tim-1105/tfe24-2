#include <fmt/chrono.h>
#include <fmt/format.h>
#include "CLI/CLI.hpp"
#include "config.h"
#include "point.hpp"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    // Create a Point object at coordinates (2,3) and print its coordinates
    Point p1(2, 3);
    p1.print();

    // Move the point by (1,-1) and print its new coordinates
    p1.move (1, -1);
    p1.print();

    // Create another Point object at the origin and print its coordinates
    Point p2;
    p2.print();

    //Create another Point object at (5,7) and calculate the distance to the first point
    Point p3(5, 7);
    double distance = p1.distance_to(p3);
    fmt::print("Distance between points: {:.2f}\n", distance);


    return 0; /* exit gracefully*/
}
