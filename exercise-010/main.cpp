#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h.in"
#include "myvector.hpp"

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


    // Test myvector
    
    tfe24::myvector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i * 10);
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        fmt::print("vec[{}] = {}\n", i, vec[i]);
    }
    

    return 0; /* exit gracefully*/
}
