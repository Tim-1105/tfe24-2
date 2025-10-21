#include <fmt/chrono.h>
#include <fmt/format.h>
#include <random>
#include <vector>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    int count = 5;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    
    try
    {
        app.add_option("-c,--count", count, "Number of iterations") ->default_val("20");
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
    fmt::print("Counter value: {}\n", count);

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);

    std::vector<int> vec;
    vec.reserve(count);
    for (int i = 0; i < count; ++i)
    {
        int value = uniform_dist(e1);
        vec.push_back(value);
        fmt::print("Random value {}: {}\n", i + 1, value);
    }
    



    return 0; /* exit gracefully*/
}
