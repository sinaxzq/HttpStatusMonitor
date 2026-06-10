#include <cpr/cpr.h>

#include <chrono>
#include <iostream>
#include <string>

int main(int argc , char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: HttpStatusMonitor <url> [url...]\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        const std::string url = argv[i];

        std::cout << "Checking " << url << " ... " << std::flush;

        const auto start = std::chrono::steady_clock::now();

        const cpr::Response response = cpr::Get(
            cpr::Url{ url } ,
            cpr::Timeout{ 5000 }
        );

        const auto end = std::chrono::steady_clock::now();

        const auto elapsedMs =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        if (response.error)
        {
            std::cout << "ERROR | " << response.error.message << "\n";
            continue;
        }

        std::cout << response.status_code << " | " << elapsedMs << " ms\n";
    }

    return 0;
}