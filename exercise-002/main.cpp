#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

int globalVar = 1; // Initialisierte globale Variable (Data Segment)

void foo() {
        fmt::print("Hello from foo\n");
    }

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

    //Teil 1: Globale Variablen (Data Segment)
    fmt::print("Value of globalVar: {}\n and Address of globalVar: {}\n", globalVar , fmt::ptr(&globalVar));

    //Teil 2: Lokale Variablen (Stack Segment)
    int localVar = 2; // Lokale Variable (Stack Segment)
    fmt::print("Value of localVar: {}\n and Address of localVar: {}\n", localVar , fmt::ptr(&localVar));

    //Teil 3: Dynamisch allozierte Variablen (Heap Segment)
    int* heapVar = new int(3); // Dynamisch allozierte Variable (Heap Segment)
    fmt::print("Value of heapVar: {}\n and Address of heapVar: {}\n", *heapVar , fmt::ptr(&heapVar));
    delete heapVar; // Speicherfreigabe

    //Teil 4: Funktionen (Code Segment)
    fmt::print("Address of function foo: {}\n", fmt::ptr(&foo));

    //Zusatz:
    /*
    Welche Art von Variablen wo gespeichert wird:
    Globale Variablen:
    Werden im Data Segment (auch "globaler Speicherbereich") abgelegt. Sie existieren während der gesamten Programmlaufzeit und sind von überall im Code erreichbar.

    Lokale Variablen:
    Werden im Stack Segment gespeichert. Sie existieren nur innerhalb des jeweiligen Funktionsaufrufs und werden beim Verlassen der Funktion automatisch gelöscht.

    Dynamisch allozierte Variablen:
    Werden im Heap Segment gespeichert. Sie werden explizit mit new (oder malloc) angelegt und müssen manuell wieder freigegeben werden (delete oder free). Sie existieren, bis sie explizit gelöscht werden.

    Funktionen:
    Der ausführbare Code einer Funktion liegt im Code Segment (Text Segment).

    
    Warum es wichtig ist, zwischen Stack und Heap zu unterscheiden.
    Stack:
    - Schneller Zugriff, automatische Speicherverwaltung
    - Begrenzte Größe (Stack Overflow möglich)
    - Geeignet für kleine, kurzlebige Daten
    
    Heap:
    - Flexibler, große Datenmengen möglich
    - Manuelle Speicherverwaltung nötig (Gefahr von Speicherlecks)
    - Geeignet für Daten, die über Funktionsgrenzen hinweg bestehen sollen
    
    Das Unterscheiden ist wichtig, um Speicher effizient zu nutzen und Fehler wie Speicherlecks oder Stack Overflows zu vermeiden.
    

    Welche Rolle Referenzen und Zeiger in diesem Zusammenhang spielen.
    Zeiger (int*)
    - Speichern die Adresse einer Variable im Speicher. Besonders wichtig für Heap-Variablen, da nur über Zeiger auf dynamisch angelegten Speicher zugegriffen werden kann.

    Referenzen (int&)
    - Sind Aliase für bestehende Variablen. Sie vereinfachen den Zugriff, ohne explizite Adressierung wie bei Zeigern.

    Zusammenhang:
    - Zeiger und Referenzen ermöglichen den Zugriff auf Speicherbereiche (Stack, Heap, Data Segment) und sind essenziell für dynamische Speicherverwaltung und effiziente Datenübergabe zwischen Funktionen.

    */
    return 0; /* exit gracefully*/
}
