#include "HttpChecker.h"
#include "ResultFormatter.h"
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

        std::cout<< formatResult(result)<<"\n";
    }

    return 0;
}