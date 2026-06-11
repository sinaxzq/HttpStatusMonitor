#include "HttpChecker.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>




namespace
{
    void printUsage()
    {
        std::cout << "Usage: HttpStatusMonitor <url> [url...]\n";
    }

    void printResult(const HttpCheckResult& result)
    {
        std::cout << result.url << " | ";

        if (!result.success)
        {
            std::cout << "ERROR | " << result.errorMessage << "\n";
            return;
        }

        std::cout << result.statusCode << " | " << result.elapsedMs << " ms\n";
    }
}

int main(int argc , char* argv[])
{
    if (argc < 2)
    {
        printUsage();
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        const std::string url = argv[i];
        const HttpCheckResult result = checkUrl(url);

        printResult(result);
    }

    return 0;
}