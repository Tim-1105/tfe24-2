#include <fmt/chrono.h>
#include <fmt/format.h>

#include <nlohmann/json.hpp>

#include "CLI/CLI.hpp"
#include "config.h"
#include "point.hpp"

// for convenience
using json = nlohmann::json;

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
    fmt::print("P1: {}\n", p1);

    // Move the point by (1,-1) and print its new coordinates
    p1.move(1, -1);
    fmt::print("Point P1 moved by (1,-1): {}\n", p1);

    // Create another Point object at the origin and print its coordinates
    Point p2(0, 0);
    fmt::print("P2: {}\n", p2);

    //Calculate the distance between P1 and P2:
    fmt::print("Distance between P1 and P2: {}\n",  p1.distance_to(p2));

    return 0; /* exit gracefully*/
}
