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
    
    //vector mit size 5 erstellen
    tfe24::myvector<int> vec2(5);
    vec2.print_status();

    //Wert 10 hinzufügen
    vec2.push_back(10);
    vec2.print_status();

    //Resize auf Size 8
    vec2.resize(8);
    vec2.print_status();

    //At Methode testen
    fmt::print("Wert an Index 5: {}\n", vec2.at(5));

    //Clear Methode testen
    vec2.clear();
    vec2.print_status();



    return 0; /* exit gracefully*/
}
